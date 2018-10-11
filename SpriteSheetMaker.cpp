#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>

int main(void)
{
	const int width = 800;
	const int height = 400;
	const int arraySize = 4;

	int	imageWidth = 64;
	int imageHeight = 64;

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *image[arraySize];
	ALLEGRO_BITMAP *outImage = NULL;

	if(!al_init())
		return -1;

	display = al_create_display(width, height);

	if(!display)
		return -1;

	al_init_image_addon();

	image[0] = al_load_bitmap("RollingLavaBallEast.bmp");
	image[1] = al_load_bitmap("RollingLavaBallWest.bmp");
	image[2] = al_load_bitmap("RollingLavaBallNorth.bmp");
	image[3] = al_load_bitmap("RollingLavaBallSouth.bmp");
	
	outImage = al_create_bitmap(imageWidth * 24, imageHeight * arraySize);

	al_set_target_bitmap(outImage);

	al_clear_to_color(al_map_rgb(0,0,0));

	for(int i=0; i<arraySize; i++)
		al_draw_bitmap(image[i], 0, imageHeight*i, 0);

	al_save_bitmap("RollingLavaBall.bmp", outImage);

	al_set_target_bitmap(al_get_backbuffer(display));

	for(int i=0; i<arraySize; i++)
	al_destroy_bitmap(image[i]);
	al_destroy_display(display);
	al_destroy_bitmap(outImage);

	return 0;

}