/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#ifndef BIGSWITCHPAD_H
#define BIGSWITCHPAD_H

#include "quantum.h"
#include "via.h"

/* enums in via for Macros*/
enum via_enums {
	UD_F = USER00,		// 	Big Script F
	CLOUD,  			//	(っ◕‿◕)っ
	FU,					//	t(-_-t)
	HAPPYFACE,			//	ʘ‿ʘ
	SHRUG,				//	¯\_(ツ)_/¯
	HEARTFACE,			//	♥‿♥
	DISFACE,			//	ಠ_ಠ
	TFLIP,				// 	(╯°□°)╯ ︵ ┻━┻
	TFLIP2,				//	┻━┻︵ \(°□°)/ ︵ ┻━┻
	SGLASS,				//	(⌐■_■)
	BEAR,				//	ʕ•ᴥ•ʔ
	HIIII,				//	⊂(◉‿◉)つ
};

// Define it so row0,column0 is bottom left and row5,column 3 is top right
#define LAYOUT_ortho_3x5( \
	K40, K41,  \
	K30, K31, K32, \
	K20, K21, K22, \
	K10, K11, K12, \
	K00, K01, K02  \
) { \
	{ K00,   K01,   K02 }, \
	{ K10,   K11,   K12 }, \
	{ K20,   K21,   K22 }, \
	{ K30,   K31,   K32 }, \
	{ K40,   K41 }  \
}

#endif
