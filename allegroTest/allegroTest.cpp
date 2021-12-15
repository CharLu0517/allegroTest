// allegroTest.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <allegro5/allegro5.h>

int main()
{
	double fps = 60;
	bool running = true;
	al_init();

	ALLEGRO_DISPLAY* display = al_create_display(640, 480);
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0/fps);
	ALLEGRO_BITMAP* bitmap = NULL;

	al_install_keyboard();
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));

	al_start_timer(timer);

	while (running)
	{
		
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			running = false;
		}
		if (event.type == ALLEGRO_EVENT_TIMER) {
			al_clear_to_color(al_map_rgb(255, 255, 255));
			al_flip_display();
		}
	}
	al_destroy_display(display);
	al_uninstall_keyboard();
	al_destroy_timer(timer);
	al_destroy_bitmap(bitmap);
	return(0);
}
