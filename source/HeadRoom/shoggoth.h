/*	   ____                            ___           _ _ _ _               
	  / __ \  /\/\   __ _ _ __ __ _   /   \_____   _(_) | (_) ___ _ __ ___ 
	 / / _` |/    \ / _` | '__/ _` | / /\ / _ \ \ / / | | | |/ _ \ '__/ __|
	| | (_| / /\/\ \ (_| | | | (_| |/ /_//  __/\ V /| | | | |  __/ |  \__ \
	 \ \__,_\/    \/\__,_|_|  \__, /___,' \___| \_/ |_|_|_|_|\___|_|  |___/
	  \____/                     |_|                                       
*/


typedef struct point_2D point_2D;
typedef struct block_2D block_2D;
typedef struct gen_obj gen_obj;


struct point_2D {
	int		_x;
	int		_y;
};

struct block_2D
{
	int		_x;
	int		_y;
	int		_width;
	int		_height;
};

struct gen_obj {
	point_2D		_pos;
	block_2D		_box;
	int 			_sprite_ID;
	int				_sprite_size;
	int				_pointer;
	void			(*_dave)(gen_obj *);

	bool			_blackSpot;
};