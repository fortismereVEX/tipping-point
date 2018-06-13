#include "lcd.h"

#include <main.h>

#include "util.h"

static void lcd_thread(void *param) {
	while(true) {
		delay(100);
	}
}

void lcd_init() {
	lcdInit(uart1);
	lcdClear(uart1);
	lcdSetBacklight(uart1, true);

	taskCreate(&lcd_thread, 0, NULL, TASK_PRIORITY_LOWEST + 1);
}

void lcd_set_text(int line, const char *text) {
	lcdPrint(uart1, line, text);
}
