SET(SOURCES ui_Inicializacao.c
    ui_Piscando.c
    ui_OlhandoDir.c
    ui_OlhandoEsq.c
    ui_Simples.c
    ui.c
    ui_comp_hook.c
    ui_helpers.c)

add_library(ui ${SOURCES})
