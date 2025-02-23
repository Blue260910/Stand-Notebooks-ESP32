# Stand-Notebooks-ESP32
Stand 3D para notebooks com suporte integrado para ESP32, controlando LED RGB via web e interface LVGL personalizável.

Stand 3D para Notebooks com Suporte para ESP32
================================================

Descrição:
----------
Stand 3D para notebooks com suporte integrado para ESP32, controlando LED RGB via web e interface LVGL personalizável.
Projeto modelado no Blender, preparado no Bambustudio e com telas criadas no Squareline Studio.

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

Estrutura do Repositório:
-------------------------
/3D_Models
    - stand_notebooks.stl
    - suporte_esp32.stl

/Firmware
    - main.ino        (Código principal do ESP32)
    - ui.h            (Arquivos gerados pelo Squareline Studio)
    - ui.c

Licença:
--------
Este projeto está licenciado sob a Licença MIT. Use como quiser.

Contribuição:
-------------
Para sugestões e melhorias, abra uma issue ou envie um pull request.

