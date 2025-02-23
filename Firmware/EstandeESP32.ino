#include <WiFi.h>
#include <WebServer.h>
#include "Display_ST7789.h"
#include "LVGL_Driver.h"
#include "ui.h"
#include <Adafruit_NeoPixel.h>

#define LED_PIN 8  // Pino do ESP32-C6 conectado ao LED RGB
#define NUM_LEDS 1


Adafruit_NeoPixel rgbLed(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

struct RGB {
    uint8_t r, g, b;
};

constexpr RGB COLOR_OFF = {0, 0, 0};
constexpr RGB COLOR_RED = {255, 255, 255};

// Credenciais Wi-Fi
const char* ssid = "Aranda_2.4";
const char* password = "vic2609ped1912";

// Criando o servidor web na porta 80
WebServer server(80);

void setColor(const RGB& color) {
    rgbLed.setPixelColor(0, rgbLed.Color(color.r, color.g, color.b));
    rgbLed.show();
}

// Página HTML com botões para controle
const char htmlPage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <title>Controle do LED</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
        body { text-align: center; font-family: Arial, sans-serif; }
        button { font-size: 20px; padding: 10px; margin: 10px; width: 150px; }
        .on { background-color: green; color: white; }
        .off { background-color: red; color: white; }
    </style>
</head>
<body>
    <h1>Controle do LED</h1>
    <button class="on" onclick="sendRequest('/ligar')">Ligar</button>
    <button class="off" onclick="sendRequest('/desligar')">Desligar</button>

    <script>
        function sendRequest(url) {
            fetch(url).then(response => console.log(response));
        }
    </script>
</body>
</html>
)rawliteral";

void handleRoot() {
    server.send(200, "text/html", htmlPage);
}

void handleLigar() {
    setColor(COLOR_RED);
    lv_scr_load(ui_Piscando);
    server.send(200, "text/plain", "LED Ligado");
}

void handleDesligar() {
    setColor(COLOR_OFF);
    lv_scr_load(ui_Piscando);
    server.send(200, "text/plain", "LED Desligado");
}


lv_timer_t *screen_timer; // Timer para alternar telas


void darUmaOlhadinha(lv_timer_t * timer) {
    int numero = random(1, 3); // Gera um número entre 1 e 2 (o limite superior é exclusivo)

    if (numero == 1) {
        lv_scr_load(ui_OlhandoDir);
    } else {
        lv_scr_load(ui_OlhandoEsq);
    }
}

void setup() {
    randomSeed(analogRead(0)); // Inicializa o gerador de números aleatórios

    // Inicializando display e interface gráfica
    Serial.begin(115200);
    Serial.println("Iniciando...");

    // Inicializa LED RGB
    rgbLed.begin();
    rgbLed.show();

    // Conectando ao Wi-Fi
    WiFi.begin(ssid, password);
    Serial.print("Conectando ao Wi-Fi...");
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    
    Serial.println("\nWi-Fi Conectado!");
    Serial.print("Endereço IP: ");
    Serial.println(WiFi.localIP());

    // Configurando rotas do servidor
    server.on("/", handleRoot);
    server.on("/ligar", handleLigar);
    server.on("/desligar", handleDesligar);

    // Iniciando servidor
    server.begin();
    LCD_Init();
    Lvgl_Init();
    ui_init();
    screen_timer = lv_timer_create(darUmaOlhadinha, 40000, NULL);
}

void loop() {
    server.handleClient();
    lv_timer_handler();     // Atualiza a LVGL para animações continuarem
    delay(5);   
}
