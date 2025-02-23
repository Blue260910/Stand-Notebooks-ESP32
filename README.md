# Stand-Notebooks-ESP32

Stand 3D para notebooks com suporte integrado para ESP32, controlando LED RGB via web e interface LVGL personalizável.

## Descrição

Este projeto consiste em um stand 3D para notebooks com um suporte integrado para ESP32. Ele permite o controle do LED RGB por meio de uma interface web e exibe uma interface gráfica personalizável com LVGL. O projeto foi modelado no Blender, preparado no Bambustudio e as telas foram criadas no Squareline Studio.

## Imagens

<img width="49%" src="https://github.com/user-attachments/assets/8c4f47e8-0c12-43b0-8655-feb312beb88b" />  
<img width="20%" src="https://github.com/user-attachments/assets/1ee9a75b-9300-4d61-b6c1-def3a66de429" />

---

## Onde Comprar o ESP32-C6

A placa ESP32-C6 pode ser adquirida diretamente da Waveshare. [Clique aqui](https://www.waveshare.com/esp32-c6-lcd-1.47.htm) para acessar a página do produto.



Funcionalidades:
----------------
- Suporte para 2 notebooks.
- Suporte integrado para ESP32.
- Controle do LED RGB por meio de servidor web.
- Interface gráfica dinâmica com LVGL.
- Telas customizáveis (veja instruções abaixo).

Instalação e Configuração:
--------------------------
1. Imprima os arquivos STL (stand e suporte para ESP32).
2. Monte o hardware conforme o projeto.
3. Abra o código no Arduino IDE ou na sua IDE preferida.
4. Configure as credenciais Wi-Fi (variáveis ssid e password) no código.
5. Compile e faça o upload do sketch para o ESP32.

Uso:
----
- Acesse o endereço IP exibido no Serial Monitor para utilizar a interface web.
- Utilize os botões para ligar/desligar o LED RGB e visualizar as telas configuradas.

Personalização das Telas:
-------------------------
Para substituir as telas atuais por uma interface personalizada:
1. Crie as novas telas utilizando o Squareline Studio.
2. Exporte os arquivos de interface (por exemplo, ui.h e ui.c).
3. Substitua os arquivos antigos pelos novos no repositório.
4. Compile e faça o upload do novo código para testar as alterações.

Licença:
--------
Este projeto está licenciado sob a Licença MIT. Use como quiser.

Contribuição:
-------------
Para sugestões e melhorias, abra uma issue ou envie um pull request.

