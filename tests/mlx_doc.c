//BASIC LIBRARIRES------------------------------------------------------------
#include <mlx.h> //
#include <X11/keyxym.h> //to get the values of all the available keyboard symbols
#include <X11/X.h> //to get different events (like key press)


//BASIC FUNCTIONS-------------------------------------------------------------
/**
 * @brief blablabla
 * 
 * @param nptr is a pointer to the string it must be converted.
 * 
 * @return the converted integer.
 * @return '0' if it doesn't convert anything
 */
void	*mlx_init();

/**
 * @brief use it always you want to apply minilibx functions. It works like a 
 *"starter"
 * 
 * @param none.
 * 
 * @return nothing
 */
void	*mlx_init();

//WINDOW FUNCTIONS------------------------------------------------------------
/**
 * @brief use it to create a new window.
 * 
 * @param mlx_ptr is the identifier of the connection to the graphic server.
 * @param size_x is the width of the window, in pixels.
 * @param size_y is the heigth of the window, in pixels.
 * @param tittle is the window's name.
 * 
 * @return a void pointer, to identificate your window (considering you can
 * open more than one window at the same time).
 */
void	*mlx_new_window(void *mlx_ptr,int size_x,int size_y,char *title)

/**
 * @brief
 * 
 * @param 
 * @param 
 * 
 * @return 
 */
int	mlx_clear_window ( void *mlx_ptr, void *win_ptr );

/**
 * @brief 
 * 
 * @param 
 * @param 
 * @param 
 * @param 
 * 
 * @return a void pointer.
 */

int	mlx_destroy_window ( void *mlx_ptr, void *win_ptr );

//EVENTS FUNCTIONS------------------------------------------------------------

/**
 * @brief use it always you want a process running continuously. It is
 * responsible for manage events (keep the window opened, clicks with the mouse
 * on the window, etc.)
 * 
 * @param mlx_ptr is the identifier of the connection to the graphic server.
 * 
 * @return 
 */
int	mlx_loop ( void *mlx_ptr );

/**
 * @brief it used when a keyboard event happens (press or release keyboard keys)
 * 
 * @param win_ptr is the identifier of the window in which 
 * we want this event happens.
 * @param funct_ptr is a pointer to function that returns an int and that takes
 * undefined parameters. It is a function that exists in your own code and 
 * will be called by mlx_loop when the user presses a key on the keyboard.
 * @param param will be given as parameter to your function funct_ptr.
 * 
 * @return 
 */
int	mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

/**
 * @brief 
 * 
 * @param 
 * @param 
 * @param 
 * 
 * @return 
 */
int	mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

/**
 * @brief 
 * Expose events are triggered when the content of a window gets lost 
 * (for example, when the minilibx's window is covered partially or entirely by
 * another and needs to be re-drawn).
 * 
 * @param 
 * @param 
 * @param 
 * 
 * @return 
 */
int	mlx_expose_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

/**
 * @brief 
 * 
 * @param 
 * @param 
 * @param 
 * 
 * @return 
 */
int	mlx_loop_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

/**
 * @brief 
 * 
 * @param 
 * @param 
 * @param 
 * @param x_event is an integer corresponding to the name of the X event.
 * You can find all the event names in the X11/X.h header.
 * @param x_mask is a bit mask corresponding to the X event.It is used by the
 * the minilibx to filter the events received by the window.
 *  * You can find all the available masks in the X11/X.h header.
 * 
 * @return 
 */
int	mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);

//PUT THINGS FUNCTIONS---------------------------------------------------------

/**
 * @brief 
 * 
 * @param mlx_ptr is the identifier of the connection to the graphic server.
 * @param mlx_ptr is the identifier of the connection to the graphic server.
 * @param mlx_ptr is the identifier of the connection to the graphic server.
 * @param mlx_ptr is the identifier of the connection to the graphic server.
 * @param mlx_ptr is the identifier of the connection to the graphic server.
 * 
 * @return 
 */
int	mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color );

/**
 * @brief 
 * 
 * @param img_ptr is the identifier of the connection to the graphic server.
 * @param bits_per_pixel is the identifier of the connection to the graphic server.
 * @param size_line is the identifier of the connection to the graphic server.
 * @param endian is the identifier of the connection to the graphic server.
 * 
 * @return 
 */
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);

/**
 * @brief 
 * 
 * @param 
 * @param 
 * @return 
 */
void	*mlx_new_image(void *mlx_ptr,int width,int height);
