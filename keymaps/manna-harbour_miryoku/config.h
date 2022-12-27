/* added by me */

#pragma once

#define XXX KC_NO


#define LAYOUT_miryoku( \
K00,  K01,  K02,  K03,  K04,         K05,  K06,  K07,  K08,  K09, \
K10,  K11,  K12,  K13,  K14,         K15,  K16,  K17,  K18,  K19, \
K20,  K21,  K22,  K23,  K24,         K25,  K26,  K27,  K28,  K29, \
N30,  N31,  K32,  K33,  K34,         K35,  K36,  K37,  N38,  N39 \
) \
LAYOUT_split_3x5_4( \
K00,  K01,  K02,  K03,  K04,                    K05,  K06,  K07,  K08,  K09, \
K10,  K11,  K12,  K13,  K14,                    K15,  K16,  K17,  K18,  K19, \
K20,  K21,  K22,  K23,  K24,                    K25,  K26,  K27,  K28,  K29, \
            K32,  K33,  K34, KC_ENT,   KC_MUTE, K35,  K36,  K37 \
)

// encoder on the right
// (will this the index 0?, no looks like the left always get index 0)
#define ENCODERS_PAD_A_RIGHT { F4 }
#define ENCODERS_PAD_B_RIGHT { F5 }

// encoder on the left
#define ENCODERS_PAD_A { F5 }
#define ENCODERS_PAD_B { F4 }
