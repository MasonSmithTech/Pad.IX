#include "quantum.h"
#ifdef OLED_ENABLE
bool oled_task_kb(void){
    oled_write_ln_P(PSTR("PAD IX"),false);
    oled_write_ln_P(PSTR("Layer: BASE"),false);
    return oled_task_user();
}
#endif
