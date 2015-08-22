@echo off
echo    C_Nul,            //   0 /* 0x00 */ >> %1
echo    C_Soh,            //   1 /* 0x01 */ >> %1
echo    C_Stx,            //   2 /* 0x02 */ >> %1
echo    C_Etx,            //   3 /* 0x03 */ >> %1
echo    C_Eot,            //   4 /* 0x04 */ >> %1
echo    C_Enq,            //   5 /* 0x05 */ >> %1
echo    C_Ack,            //   6 /* 0x06 */ >> %1
echo    C_Bel,            //   7 /* 0x07 */ >> %1
echo    C_Bs,             //   8 /* 0x08 */ >> %1
echo    C_Ht,             //   9 /* '\t' 0x09 */ >> %1
echo    C_Lf,             //  10 /* '\n' 0x0a */ >> %1
echo    C_Vt,             //  11 /* 0x0b */ >> %1
echo    C_Ff,             //  12 /* '\f' 0x0c */ >> %1
echo    C_Cr,             //  13 /* '\r' 0x0d */ >> %1
echo    C_So,             //  14 /* 0x0e */ >> %1
echo    C_Si,             //  15 /* 0x0f */ >> %1
echo    C_Dle,            //  16 /* 0x10 */ >> %1
echo    C_Dc1,            //  17 /* 0x11 */ >> %1
echo    C_Dc2,            //  18 /* 0x12 */ >> %1
echo    C_Dc3,            //  19 /* 0x13 */ >> %1
echo    C_Dc4,            //  20 /* 0x14 */ >> %1
echo    C_Nak,            //  21 /* 0x15 */ >> %1
echo    C_Syn,            //  22 /* 0x16 */ >> %1
echo    C_Etb,            //  23 /* 0x17 */ >> %1
echo    C_Can,            //  24 /* 0x18 */ >> %1
echo    C_Em,             //  25 /* 0x19 */ >> %1
echo    C_Sub,            //  26 /* 0x1a */ >> %1
echo    C_Esc,            //  27 /* 0x1b */ >> %1
echo    C_Fs,             //  28 /* 0x1c */ >> %1
echo    C_Gs,             //  29 /* 0x1d */ >> %1
echo    C_Rs,             //  30 /* 0x1e */ >> %1
echo    C_Us,             //  31 /* 0x1f */ >> %1
echo // >> %1
echo    C_Spc,            //  32 /* Space */ >> %1
echo    C_Excl,           //  33 /* !  Exclamation Mark (s/auktukas) */ >> %1
echo    C_Quote,          //  34 /* "  Quotation Mark (kabute%s) */ >> %1
echo    C_Numb,           //  35 /* #  Number Sign (Numerio zenklas) */ >> %1
echo    C_Doll,           //  36 /* $  Currency Sign (Pinigu zenklas) */ >> %1
echo    C_Perc,           //  37 /* %  Per Cent Sign (procento z/enklas) */ >> %1
echo    C_Amp,            //  38 /* &  Ampersand (Ampersandas) */ >> %1
echo    C_Apost,          //  39 /* '  Apostrophe (Apostrofa, apostrofas, kablelio formos) C_Acute; C_AcuteNcomb */ >> %1
echo    C_Lpar,           //  40 /* (  Left Parenthesis (kairysis skliaustas) */ >> %1
echo    C_Rpar,           //  41 /* )  Right Parenthesis (des/inysis skliaustas) */ >> %1
echo    C_Ast,            //  42 /* *  Asterisk (Zvaigzdute) */ >> %1
echo    C_Plus,           //  43 /* +  Plus Sign (pliusas) */ >> %1
echo    C_Comma,          //  44 /* ,  Comma (kablelis) */ >> %1
echo    C_Dash,           //  45 /* -  Dash, Hyphen, Minus Sign (minusas) */ // former C_Minus >> %1
echo    C_Point,          //  46 /* .  Full Stop, Period, Point (tas/kas) */ >> %1
echo    C_Slash,          //  47 /* /  Slash, Solidus (Istrizas bruksnys) */ >> %1
echo    C_0,              //  48 /* 0 */ >> %1
echo    C_1,              //  49 /* 1 */ >> %1
echo    C_2,              //  50 /* 2 */ >> %1
echo    C_3,              //  51 /* 3 */ >> %1
echo    C_4,              //  52 /* 4 */ >> %1
echo    C_5,              //  53 /* 5 */ >> %1
echo    C_6,              //  54 /* 6 */ >> %1
echo    C_7,              //  55 /* 7 */ >> %1
echo    C_8,              //  56 /* 8 */ >> %1
echo    C_9,              //  57 /* 9 */ >> %1
echo    C_Colon,          //  58 /* :  Colon (dvitas/kis) */ >> %1
echo    C_Semic,          //  59 /* ;  Semi-colon (kabliatas/kis) */ >> %1
echo    C_Less,           //  60 /* <  Less than Sign (maz/iau) */ >> %1
echo    C_Eq,             //  61 /* =  Equals Sign (lygybe%s z/enklas) */ >> %1
echo    C_Great,          //  62 /* >  Greater than Sign (daugiau) */ >> %1
echo    C_Quest,          //  63 /* ?  Question Mark (klaustukas) */ >> %1
echo // >> %1
echo    C_At,             //  64 /* @  Commercial At (Prekybinis zenklas "Pas") */ >> %1
echo    C_A,              //  65 /* A */ >> %1
echo    C_B,              //  66 /* B */ >> %1
echo    C_C,              //  67 /* C */ >> %1
echo    C_D,              //  68 /* D */ >> %1
echo    C_E,              //  69 /* E */ >> %1
echo    C_F,              //  70 /* F */ >> %1
echo    C_G,              //  71 /* G */ >> %1
echo    C_H,              //  72 /* H */ >> %1
echo    C_I,              //  73 /* I */ >> %1
echo    C_J,              //  74 /* J */ >> %1
echo    C_K,              //  75 /* K */ >> %1
echo    C_L,              //  76 /* L */ >> %1
echo    C_M,              //  77 /* M */ >> %1
echo    C_N,              //  78 /* N */ >> %1
echo    C_O,              //  79 /* O */ >> %1
echo    C_P,              //  80 /* P */ >> %1
echo    C_Q,              //  81 /* Q */ >> %1
echo    C_R,              //  82 /* R */ >> %1
echo    C_S,              //  83 /* S */ >> %1
echo    C_T,              //  84 /* T */ >> %1
echo    C_U,              //  85 /* U */ >> %1
echo    C_V,              //  86 /* V */ >> %1
echo    C_W,              //  87 /* W */ >> %1
echo    C_X,              //  88 /* X */ >> %1
echo    C_Y,              //  89 /* Y */ >> %1
echo    C_Z,              //  90 /* Z */ >> %1
echo    C_Lbrack,         //  91 /* [  Left Square Bracket (Kairysis lauztinis skliaustas) */ >> %1
echo    C_Lslash,         //  92 /* \  Reverse Solidus, Reverse Slash (Atvirkscias istrizas bruksnys) */ >> %1
echo    C_Rbrack,         //  93 /* ]  Right Square Bracket (Desinysis lauztinis skliaustas) */ >> %1
echo    C_Circ,           //  94 /* ^  Circumflex Accent (Cirkumfleksas), standalone, nekombinacinis (diakritas) */ >> %1
echo    C_Underl,         //  95 /* _  Underline (Pabraukimas) */ >> %1
echo // >> %1
echo    C_Grave,          //  96 /* `  Grave Accent (gravis), standalone, nekombinacinis (diakritas) */ >> %1
echo    C_a,              //  97 /* a */ >> %1
echo    C_b,              //  98 /* b */ >> %1
echo    C_c,              //  99 /* c */ >> %1
echo    C_d,              // 100 /* d */ >> %1
echo    C_e,              // 101 /* e */ >> %1
echo    C_f,              // 102 /* f */ >> %1
echo    C_g,              // 103 /* g */ >> %1
echo    C_h,              // 104 /* h */ >> %1
echo    C_i,              // 105 /* i */ >> %1
echo    C_j,              // 106 /* j */ >> %1
echo    C_k,              // 107 /* k */ >> %1
echo    C_l,              // 108 /* l */ >> %1
echo    C_m,              // 109 /* m */ >> %1
echo    C_n,              // 110 /* n */ >> %1
echo    C_o,              // 111 /* o */ >> %1
echo    C_p,              // 112 /* p */ >> %1
echo    C_q,              // 113 /* q */ >> %1
echo    C_r,              // 114 /* r */ >> %1
echo    C_s,              // 115 /* s */ >> %1
echo    C_t,              // 116 /* t */ >> %1
echo    C_u,              // 117 /* u */ >> %1
echo    C_v,              // 118 /* v */ >> %1
echo    C_w,              // 119 /* w */ >> %1
echo    C_x,              // 120 /* x */ >> %1
echo    C_y,              // 121 /* y */ >> %1
echo    C_z,              // 122 /* z */ >> %1
echo    C_Lcurl,          // 123 /* {  Left Curly Bracket (Kairysis riestinis skliaustas) */ >> %1
echo    C_Vertl,          // 124 /* |  Vertical Line (Vertikali Linija), C_v_b */ >> %1
echo    C_Rcurl,          // 125 /* }  Right Curly Bracket (Desinysis riestinis skliaustas) */ >> %1
echo    C_Tilde,          // 126 /* ~  Tilde (Overline) (Tilde, Bruksnys virsuje), standalone, net ne diakritas - TEX-e stambesnis ir per viduri; C_TildeNcomb; C_TildeAcc */ >> %1
echo // >> %1
echo    C_Del,            // 127 >> %1
echo // >> %1
echo    C_AE,             // 128 >> %1
echo    C_ae,             // 129 >> %1
echo    C_OE,             // 130 >> %1
echo    C_oe,             // 131 >> %1
echo    C_IJ,             // 132 >> %1
echo    C_ij,             // 133 >> %1
echo    C_ss,             // 134 /* sharp s (german, C_beta) */ >> %1
echo // >> %1
echo    C_A_Cyr,          // 135 >> %1
echo    C_B_Cyr,          // 136 >> %1
echo    C_V_Cyr,          // 137 >> %1
echo    C_G_Cyr,          // 138 >> %1
echo    C_D_Cyr,          // 139 >> %1
echo    C_E_Cyr,          // 140 >> %1
echo    C_Zh_Cyr,         // 141 >> %1
echo    C_Z_Cyr,          // 142 >> %1
echo    C_I_Cyr,          // 143 >> %1
echo    C_J_Cyr,          // 144 >> %1
echo    C_K_Cyr,          // 145 >> %1
echo    C_L_Cyr,          // 146 >> %1
echo    C_M_Cyr,          // 147 >> %1
echo    C_N_Cyr,          // 148 >> %1
echo    C_O_Cyr,          // 149 >> %1
echo    C_P_Cyr,          // 150 >> %1
echo    C_R_Cyr,          // 151 >> %1
echo    C_S_Cyr,          // 152 >> %1
echo    C_T_Cyr,          // 153 >> %1
echo    C_U_Cyr,          // 154 >> %1
echo    C_F_Cyr,          // 155 >> %1
echo    C_H_Cyr,          // 156 >> %1
echo    C_C_Cyr,          // 157 >> %1
echo    C_Ch_Cyr,         // 158 >> %1
echo    C_Sh_Cyr,         // 159 >> %1
echo    C_Shch_Cyr,       // 160 >> %1
echo    C_Hard_Cyr,       // 161 >> %1
echo    C_Y_Cyr,          // 162 >> %1
echo    C_Soft_Cyr,       // 163 >> %1
echo    C_Ee_Cyr,         // 164 >> %1
echo    C_Yu_Cyr,         // 165 // former C_Ju_Cyr >> %1
echo    C_Ya_Cyr,         // 166 // former C_Ja_Cyr >> %1
echo // >> %1
echo    C_a_Cyr,          // 167 >> %1
echo    C_b_Cyr,          // 168 >> %1
echo    C_v_Cyr,          // 169 >> %1
echo    C_g_Cyr,          // 170 >> %1
echo    C_d_Cyr,          // 171 >> %1
echo    C_e_Cyr,          // 172 >> %1
echo    C_zh_Cyr,         // 173 >> %1
echo    C_z_Cyr,          // 174 >> %1
echo    C_i_Cyr,          // 175 >> %1
echo    C_j_Cyr,          // 176 >> %1
echo    C_k_Cyr,          // 177 >> %1
echo    C_l_Cyr,          // 178 >> %1
echo    C_m_Cyr,          // 179 >> %1
echo    C_n_Cyr,          // 180 >> %1
echo    C_o_Cyr,          // 181 >> %1
echo    C_p_Cyr,          // 182 >> %1
echo    C_r_Cyr,          // 183 >> %1
echo    C_s_Cyr,          // 184 >> %1
echo    C_t_Cyr,          // 185 >> %1
echo    C_u_Cyr,          // 186 >> %1
echo    C_f_Cyr,          // 187 >> %1
echo    C_h_Cyr,          // 188 >> %1
echo    C_c_Cyr,          // 189 >> %1
echo    C_ch_Cyr,         // 190 >> %1
echo    C_sh_Cyr,         // 191 >> %1
echo    C_shch_Cyr,       // 192 >> %1
echo    C_hard_Cyr,       // 193 >> %1
echo    C_y_Cyr,          // 194 >> %1
echo    C_soft_Cyr,       // 195 >> %1
echo    C_ee_Cyr,         // 196 >> %1
echo    C_yu_Cyr,         // 197 // former C_ju_Cyr >> %1
echo    C_ya_Cyr,         // 198 // former C_ja_Cyr >> %1
echo // >> %1
echo                      // ---------------------------- >> %1
echo                      /* Additional greek chars variations follow later */ >> %1
echo // >> %1
echo    C_Alpha,          // 199 >> %1
echo    C_Beta,           // 200 >> %1
echo    C_Gamma,          // 201 >> %1
echo    C_Delta,          // 202 >> %1
echo    C_Epsilon,        // 203 >> %1
echo    C_Zeta,           // 204 >> %1
echo    C_Eta,            // 205 >> %1
echo    C_Theta,          // 206 >> %1
echo    C_Jota,           // 207 >> %1
echo    C_Kappa,          // 208 >> %1
echo    C_Lambda,         // 209 >> %1
echo    C_My,             // 210 >> %1
echo    C_Ny,             // 211 >> %1
echo    C_Xi,             // 212 >> %1
echo    C_Omicron,        // 213 // buv. C_Omikron >> %1
echo    C_Pi,             // 214 >> %1
echo    C_Rho,            // 215 >> %1
echo    C_Sigma,          // 216 >> %1
echo    C_Tau,            // 217 >> %1
echo    C_Ypsilon,        // 218 >> %1
echo    C_Phi,            // 219 >> %1
echo    C_Chi,            // 220 >> %1
echo    C_Psi,            // 221 >> %1
echo    C_Omega,          // 222 >> %1
echo // >> %1
echo    C_alpha,          // 223 >> %1
echo    C_beta,           // 224 >> %1
echo    C_gamma,          // 225 >> %1
echo    C_delta,          // 226 >> %1
echo    C_epsilon,        // 227 // curly epsilon >> %1
echo    C_zeta,           // 228 >> %1
echo    C_eta,            // 229 >> %1
echo    C_theta,          // 230 // straight theta >> %1
echo    C_jota,           // 231 >> %1
echo    C_kappa,          // 232 // straight kappa >> %1
echo    C_lambda,         // 233 >> %1
echo    C_my,             // 234 >> %1
echo    C_ny,             // 235 >> %1
echo    C_xi,             // 236 >> %1
echo    C_omicron,        // 237 // buv. C_omikron >> %1
echo    C_pi,             // 238 // straight pi >> %1
echo    C_rho,            // 239 // straight rho >> %1
echo    C_sigma,          // 240 // inner sigma >> %1
echo    C_tau,            // 241 >> %1
echo    C_ypsilon,        // 242 >> %1
echo    C_phi,            // 243 // straight phi >> %1
echo    C_chi,            // 244 >> %1
echo    C_psi,            // 245 >> %1
echo    C_omega,          // 246 >> %1
echo // >> %1
echo    C_delta_Dash,     // 247 /* skardi th */ // former C_delt_Mn >> %1
echo // >> %1
echo                      // ---------------------------- >> %1
echo                      /* All accents have no width (over the next letter) */ >> %1
echo                      /* more accents later - C_...Acc */ >> %1
echo                      // kombinaciniai diakritai >> %1
echo // >> %1
echo    C_Acute,          // 248 /* '  Acute (aku/tas, C_Apost, des/inysis kirtis) (zr. dar C_AcuteNcomb) */ >> %1
echo    C_Dacut,          // 249 /* '' Double Acute */ >> %1
echo    C_Ogon,           // 250 /* ,  Ogonek (nosine) */ >> %1
echo    C_Adot,           // 251 /* .  Dot Above (. virsuje) */ >> %1
echo    C_Car,            // 252 /* v  Caron (Pauksciukas) */ >> %1
echo    C_Macr,           // 253 /* _  Macron, Overline (bruksnys virsuje), C_Oline */ >> %1
echo    C_Diaer,          // 254 /* .. Diaeresis (Umlaut) */ >> %1
echo    C_Ring,           // 255 /* o  Ring (Circle) Above (o virsuje, degree) */ >> %1
echo    C_Tacom,          // 256 /* '  Turned Comma Above */ >> %1
echo    C_Bcomma,         // 257 /* ,  Comma Bellow */ >> %1
echo    C_Cedil,          // 258 /* ,  Cedilla (atbula nosine) */ >> %1
echo // >> %1
echo                      // ---------------------------- >> %1
echo // >> %1
echo    C_A_Ogon,         // 259 /* A, */ >> %1
echo    C_a_Ogon,         // 260 /* a, */ >> %1
echo    C_E_Ogon,         // 261 /* E, */ >> %1
echo    C_e_Ogon,         // 262 /* e, */ >> %1
echo    C_I_Ogon,         // 263 /* I, */ >> %1
echo    C_i_Ogon,         // 264 /* i, */ >> %1
echo    C_U_Ogon,         // 265 /* U, */ >> %1
echo    C_u_Ogon,         // 266 /* u, */ >> %1
echo // >> %1
echo    C_E_Adot,         // 267 /* E. */ >> %1
echo    C_e_Adot,         // 268 /* e. */ >> %1
echo    C_Z_Adot,         // 269 /* Z. */ >> %1
echo    C_z_Adot,         // 270 /* z. */ >> %1
echo // >> %1
echo    C_G_Cyr_Adot,     // 271 /* G Cyr . */ >> %1
echo    C_g_Cyr_Adot,     // 272 /* g Cyr . */ >> %1
echo // >> %1
echo    C_C_Car,          // 273 /* Cv */ >> %1
echo    C_c_Car,          // 274 /* cv */ >> %1
echo    C_D_Car,          // 275 /* Dv */ >> %1
echo    C_d_Car,          // 276 /* dv */ >> %1
echo    C_E_Car,          // 277 /* Ev */ >> %1
echo    C_e_Car,          // 278 /* ev */ >> %1
echo    C_L_Car,          // 279 /* Lv */ >> %1
echo    C_l_Car,          // 280 /* lv */ >> %1
echo    C_N_Car,          // 281 /* Nv */ >> %1
echo    C_n_Car,          // 282 /* nv */ >> %1
echo    C_R_Car,          // 283 /* Rv */ >> %1
echo    C_r_Car,          // 284 /* rv */ >> %1
echo    C_S_Car,          // 285 /* Sv */ >> %1
echo    C_s_Car,          // 286 /* sv */ >> %1
echo    C_T_Car,          // 287 /* Tv */ >> %1
echo    C_t_Car,          // 288 /* tv */ >> %1
echo    C_Z_Car,          // 289 /* Zv */ >> %1
echo    C_z_Car,          // 290 /* zv */ >> %1
echo // >> %1
echo    C_A_Macr,         // 291 /* A_ */ >> %1
echo    C_a_Macr,         // 292 /* a_ */ >> %1
echo    C_E_Macr,         // 293 /* E_ */ >> %1
echo    C_e_Macr,         // 294 /* e_ */ >> %1
echo    C_I_Macr,         // 295 /* I_ */ >> %1
echo    C_i_Macr,         // 296 /* i_ */ >> %1
echo    C_O_Macr,         // 297 /* O_ */ >> %1
echo    C_o_Macr,         // 298 /* o_ */ >> %1
echo    C_U_Macr,         // 299 /* U_ */ >> %1
echo    C_u_Macr,         // 300 /* u_ */ >> %1
echo // >> %1
echo    C_A_Diaer,        // 301 /* A.. */ >> %1
echo    C_a_Diaer,        // 302 /* a.. */ >> %1
echo    C_E_Diaer,        // 303 /* E.. */ >> %1
echo    C_e_Diaer,        // 304 /* e.. */ >> %1
echo    C_I_Diaer,        // 305 /* I.. */ >> %1
echo    C_i_Diaer,        // 306 /* i.. */ >> %1
echo    C_O_Diaer,        // 307 /* O.. */ >> %1
echo    C_o_Diaer,        // 308 /* o.. */ >> %1
echo    C_U_Diaer,        // 309 /* U.. */ >> %1
echo    C_u_Diaer,        // 310 /* u.. */ >> %1
echo    C_Y_Diaer,        // 311 /* Y.. */ >> %1
echo    C_y_Diaer,        // 312 /* y.. */ >> %1
echo // >> %1
echo    C_E_Cyr_Diaer,    // 313 /* E.. */ >> %1
echo    C_e_Cyr_Diaer,    // 314 /* e.. */ >> %1
echo // >> %1
echo    C_A_Ring,         // 315 /* Ao */ >> %1
echo    C_a_Ring,         // 316 /* ao */ >> %1
echo    C_U_Ring,         // 317 /* Uo */ >> %1
echo    C_u_Ring,         // 318 /* uo */ >> %1
echo // >> %1
echo    C_G_Tacom,        // 319 /* G' */ >> %1
echo    C_g_Tacom,        // 320 /* g' */ >> %1
echo // >> %1
echo    C_G_Bcomma,       // 321 /* G, */ >> %1
echo    C_g_Bcomma,       // 322 /* g, */ >> %1
echo    C_K_Bcomma,       // 323 /* K, */ >> %1
echo    C_k_Bcomma,       // 324 /* k, */ >> %1
echo    C_L_Bcomma,       // 325 /* L, */ >> %1
echo    C_l_Bcomma,       // 326 /* l, */ >> %1
echo    C_N_Bcomma,       // 327 /* N, */ >> %1
echo    C_n_Bcomma,       // 328 /* n, */ >> %1
echo    C_R_Bcomma,       // 329 /* R, */ >> %1
echo    C_r_Bcomma,       // 330 /* r, */ >> %1
echo // >> %1
echo    C_C_Cedil,        // 331 /* C, */ >> %1
echo    C_c_Cedil,        // 332 /* c, */ >> %1
echo    C_S_Cedil,        // 333 /* S, */ >> %1
echo    C_s_Cedil,        // 334 /* s, */ >> %1
echo    C_T_Cedil,        // 335 /* T, */ >> %1
echo    C_t_Cedil,        // 336 /* t, */ >> %1
echo // >> %1
echo    C_A_Grave,        // 337 /* A` */ >> %1
echo    C_a_Grave,        // 338 /* a` */ >> %1
echo    C_E_Grave,        // 339 /* E` */ >> %1
echo    C_e_Grave,        // 340 /* e` */ >> %1
echo    C_I_Grave,        // 341 /* I` */ >> %1
echo    C_i_Grave,        // 342 /* i` */ >> %1
echo    C_O_Grave,        // 343 /* O` */ >> %1
echo    C_o_Grave,        // 344 /* o` */ >> %1
echo    C_U_Grave,        // 345 /* U` */ >> %1
echo    C_u_Grave,        // 346 /* u` */ >> %1
echo // >> %1
echo    C_A_Acute,        // 347 /* A' */ >> %1
echo    C_a_Acute,        // 348 /* a' */ >> %1
echo    C_C_Acute,        // 349 /* C' */ >> %1
echo    C_c_Acute,        // 350 /* c' */ >> %1
echo    C_E_Acute,        // 351 /* E' */ >> %1
echo    C_e_Acute,        // 352 /* e' */ >> %1
echo    C_I_Acute,        // 353 /* I' */ >> %1
echo    C_i_Acute,        // 354 /* i' */ >> %1
echo    C_L_Acute,        // 355 /* L' */ >> %1
echo    C_l_Acute,        // 356 /* l' */ >> %1
echo    C_N_Acute,        // 357 /* N' */ >> %1
echo    C_n_Acute,        // 358 /* n' */ >> %1
echo    C_O_Acute,        // 359 /* O' */ >> %1
echo    C_o_Acute,        // 360 /* o' */ >> %1
echo    C_R_Acute,        // 361 /* R' */ >> %1
echo    C_r_Acute,        // 362 /* r' */ >> %1
echo    C_S_Acute,        // 363 /* S' */ >> %1
echo    C_s_Acute,        // 364 /* s' */ >> %1
echo    C_U_Acute,        // 365 /* U' */ >> %1
echo    C_u_Acute,        // 366 /* u' */ >> %1
echo    C_Y_Acute,        // 367 /* Y' */ >> %1
echo    C_y_Acute,        // 368 /* y' */ >> %1
echo    C_Z_Acute,        // 369 /* Z' */ >> %1
echo    C_z_Acute,        // 370 /* z' */ >> %1
echo // >> %1
echo    C_K_Cyr_Acute,    // 371 /* K Cyr ' */ >> %1
echo    C_k_Cyr_Acute,    // 372 /* k Cyr ' */ >> %1
echo // >> %1
echo    C_O_Dacut,        // 373 /* O'' */ >> %1
echo    C_o_Dacut,        // 374 /* o'' */ >> %1
echo    C_U_Dacut,        // 375 /* U'' */ >> %1
echo    C_u_Dacut,        // 376 /* u'' */ >> %1
echo // >> %1
echo    C_A_Tilde,        // 377 /* A~ */ >> %1
echo    C_a_Tilde,        // 378 /* a~ */ >> %1
echo    C_N_Tilde,        // 379 /* N~ */ >> %1
echo    C_n_Tilde,        // 380 /* n~ */ >> %1
echo    C_O_Tilde,        // 381 /* O~ */ >> %1
echo    C_o_Tilde,        // 382 /* o~ */ >> %1
echo // >> %1
echo    C_L_Slash,        // 383 /* L/ */ >> %1
echo    C_l_Slash,        // 384 /* l/ */ >> %1
echo    C_O_Slash,        // 385 /* O/ */ >> %1
echo    C_o_Slash,        // 386 /* o/ */ >> %1
echo // >> %1
echo    C_A_Circ,         // 387 /* A^ */ >> %1
echo    C_a_Circ,         // 388 /* a^ */ >> %1
echo    C_E_Circ,         // 389 /* E^ */ >> %1
echo    C_e_Circ,         // 390 /* e^ */ >> %1
echo    C_I_Circ,         // 391 /* I^ */ >> %1
echo    C_i_Circ,         // 392 /* i^ */ >> %1
echo    C_O_Circ,         // 393 /* O^ */ >> %1
echo    C_o_Circ,         // 394 /* o^ */ >> %1
echo    C_U_Circ,         // 395 /* U^ */ >> %1
echo    C_u_Circ,         // 396 /* u^ */ >> %1
echo // >> %1
echo    C_D_Dash,         // 397 /* D- Island. */   // former C_D_Minus >> %1
echo    C_d_Dash,         // 398 /* d- */           // former C_d_Minus >> %1
echo    C_H_Dash,         // 399 /* H- */           // former C_H_Minus >> %1
echo    C_h_Dash,         // 400 /* h- */           // former C_h_Minus >> %1
echo    C_P_Dash,         // 401 /* P- */           // former C_P_Minus >> %1
echo    C_p_Dash,         // 402 /* p- */           // former C_p_Minus >> %1
echo // >> %1
echo    C_NBSP,           // 403 /* No break space */ >> %1
echo // >> %1
echo    C_Rouble,         // 404 /* rublis, $ Cyr */ >> %1
echo    C_Pound,          // 405 /* svaras, L/ */ >> %1
echo    C_Yenna,          // 406 /* jena, Y- */ >> %1
echo    C_cent,           // 407 /* c/ */ >> %1
echo // >> %1
echo    C_Para,           // 408 /* paragrafas, # engl. */ >> %1
echo    C_Pren,           // 409 /* paragraph end sign (pastraipos pabaiga, C_pi - pi) */ >> %1
echo    C_Multipl,        // 410 /* x */ >> %1
echo    C_Divide,         // 411 /* -:- */ >> %1
echo    C_PlMin,          // 412 /* -+- */ >> %1
echo    C_1up,            // 413 /* 1 virsuj */ >> %1
echo    C_2up,            // 414 /* 2 virsuj, kvadratu */ >> %1
echo    C_3up,            // 415 /* 3 virsuj, kubu */ >> %1
echo    C_a_up,           // 416 /* a virsuj */ >> %1
echo    C_o_up,           // 417 /* o virsuj */ >> %1
echo    C_Half,           // 418 /* 1/2 */ >> %1
echo    C_Quart,          // 419 /* 1/4 */ >> %1
echo    C_34,             // 420 /* 3/4 */ >> %1
echo    C_Ldopang,        // 421 /* << - rusiska kabute */ >> %1
echo    C_Rdopang,        // 422 /* >> - rusiska kabute */ >> %1
echo    C_Lang,           // 423 /* < */ >> %1
echo    C_Rang,           // 424 /* > */ >> %1
echo    C_Dvertl,         // 425 /* | Koi-7-0 */ >> %1
echo    C_Rminbr,         // 426 /* ^ Koi-7-0 ( not, neiginys, -| ) */ >> %1
echo    C_Lminbr,         // 427 /* |- */ >> %1
echo    C_Lpoint,         // 428 /* mazas taskas vidury, daugybos zenklas */ >> %1
echo    C_Bpoint,         // 429 /* bullet, didelis taskas vidury */ // naudojamas homonimø identifikavimui (DOUBLE_ENTRIES_KPCHAR), tikram bullet'ui naudoti C_hBpoint >> %1
echo    C_LBquote,        // 430 /* ,, (" left bellow, double comma, liet. kaire, 99 apacioje) */ >> %1
echo    C_LAquote,        // 431 /* `` (" left above, reversed double comma above, angl. kaire, liet. desine, 66 virsuj) */ >> %1
echo    C_Rquote,         // 432 /* '' (" right, double comma above, angl. desine, 99 virsuj) */ >> %1
echo    C_LBapost,        // 433 /* , (' left bellow, comma, liet. kaire, 9 apacioj) */ >> %1
echo    C_LAapost,        // 434 /* ` (' left above, C_Grave, reversed comma above, angl. kaire, liet. desine, 6 virsuj) */ >> %1
echo    C_Rapost,         // 435 /* ' (' right, C_Apost, comma above, angl. desine, 9 virsuj) */ >> %1
echo // >> %1
echo    C_Qst_Ov,         // 436 /* apverstas ? */ >> %1
echo    C_Ex_Ov,          // 437 /* apverstas ! */ >> %1
echo    C_Dots,           // 438 /* ... daugtaskis, ellipsis */ >> %1
echo    C_Prom,           // 439 /* %o promiles */ >> %1
echo    C_TM,             // 440 /* TM, Trade Mark */ >> %1
echo    C_CO,             // 441 /* (C) Copyright */ >> %1
echo    C_RO,             // 442 /* (R) */ >> %1
echo // >> %1
echo                      /* Additional greek chars, look SGML DTD */ >> %1
echo // >> %1
echo    C_epsilon_var,    // 443 // straight epsilon >> %1
echo    C_theta_var,      // 444 // curly theta >> %1
echo    C_DiGamma,        // 445 >> %1
echo    C_digamma,        // 446 >> %1
echo    C_kappa_var,      // 447 // curly kappa >> %1
echo    C_DiLambda,       // 448 >> %1
echo    C_dilambda,       // 449 >> %1
echo    C_pi_var,         // 450 // curly pi, like C_omega >> %1
echo    C_rho_var,        // 451 // curly rho >> %1
echo    C_Sigma_var,      // 452 // like "S" >> %1
echo    C_sigma_var,      // 453 // final sigma, like "s" >> %1
echo    C_phi_var,        // 454 // curly phi >> %1
echo // >> %1
echo                      // ---------------------------- >> %1
echo                      /* additional accents, all of them have no width (over the next letter) */ >> %1
echo                      // kombinaciniai diakritai >> %1
echo // >> %1
echo    C_GraveAcc,       // 455 /* `  Grave Accent (C_Grave, kairysis kirtis), over the next letter */ >> %1
echo    C_CircAcc,        // 456 /* ^  Circumflex Accent (C_Circ), over the next letter */ >> %1
echo    C_TildeAcc,       // 457 /* ~  Tilde (C_Tilde), over the next letter; C_TildeNcomb, C_Tilde */ >> %1
echo    C_BreveAcc,       // 458 /* u  (lankelis virsuje) */ >> %1
echo    C_SlashAcc,       // 459 /* /  Slash, Solidus (Istrizas bruksnys per raide) */ >> %1
echo    C_BdotAcc,        // 460 /* .  Dot bellow */ >> %1
echo    C_UnderlAcc,      // 461 /* _  Underline (Pabraukimas) */ >> %1
echo // >> %1
echo    C_prim,           // 462 /* strichas prie raides (C_Acute, C_Apost; C_AcuteNcomb) */ >> %1
echo    C_dprim,          // 463 /* du strichai (C_Dacut) */ >> %1
echo // >> %1
echo                      // ---------------------------- >> %1
echo // >> %1
echo    C_Each,           // 464 /* V - "kiekvienam" - apversta A raide */ >> %1
echo    C_Exists,         // 465 /* E - "egzistuoja" - apversta E raide */ >> %1
echo // >> %1
echo    C_Aleph,          // 466 /* N - alefas */ >> %1
echo    C_Im,             // 467 /* C_I_Got */ >> %1
echo    C_Re,             // 468 /* C_R_Got */ >> %1
echo    C_wp,             // 469 /* C_p_Got */ >> %1
echo // >> %1
echo    C_le,             // 470 /* <= - maziau arba lygu */ >> %1
echo    C_ge,             // 471 /* >= - daugiau arba lygu */ >> %1
echo    C_ne,             // 472 /* =/= - nelygu */ >> %1
echo    C_ll,             // 473 /* << */ >> %1
echo    C_gg,             // 474 /* >> */ >> %1
echo    C_sim,            // 475 /* ~ - panasu */ >> %1
echo    C_simeq,          // 476 /* ~- - panasu arba sutampa */ >> %1
echo    C_approx,         // 477 /* ~~ - apytiksliai lygu */ >> %1
echo    C_cong,           // 478 /* ~= - kongruentu */ >> %1
echo    C_equiv,          // 479 /* = - triguba lygybe - ekvivalentu */ >> %1
echo // >> %1
echo    C_sqrt,           // 480 /* square root */ >> %1
echo    C_int,            // 481 /* integralas */ >> %1
echo    C_oint,           // 482 /* kreivinis integralas */ >> %1
echo    C_Sum,            // 483 /* sum sign (C_Sigma) */ >> %1
echo    C_Prod,           // 484 /* C_Pi */ >> %1
echo    C_O_times,        // 485 /* OX - O perbraukta kryzmai */ >> %1
echo    C_O_plus,         // 486 /* O+ - O perbraukta pliusu */ >> %1
echo // >> %1
echo    C_infty,          // 487 /* infinity - begalybe */ >> %1
echo    C_propto,         // 488 /* (C_alpha) */ >> %1
echo    C_part,           // 489 /* partial (C_delta) */ >> %1
echo    C_empty,          // 490 /* O/ (C_O_Slash) */ >> %1
echo    C_triangle,       // 491 /* lygiakrastis trikampis, ~C_Delta */ >> %1
echo    C_nabla,          // 492 /* V - C_Delta apversta, lygiasonis siauras trikampis */ >> %1
echo // >> %1
echo    C_perp,           // 493 /* T apversta - statmena */ >> %1
echo    C_angle,          // 494 /* < - kampas (geom.) */ >> %1
echo // >> %1
echo    C_langle,         // 495 /* < - skliaustas !!! keisti i C_Lang */ >> %1
echo    C_rangle,         // 496 /* > - skliaustas !!! keisti i C_Rang */ >> %1
echo // >> %1
echo    C_cap,            // 497 /* U apversta - pjuvis */ >> %1
echo    C_cup,            // 498 /* U - junginys */ >> %1
echo // >> %1
echo    C_vee,            // 499 /* V */ >> %1
echo    C_wedge,          // 500 /* C_Lambda */ >> %1
echo // >> %1
echo    C_supset,         // 501 /* D - virsaibis */ >> %1
echo    C_supseteq,       // 502 /* D= - virsaibis arba sutampa */ >> %1
echo    C_subset,         // 503 /* C - poaibis */ >> %1
echo    C_subseteq,       // 504 /* C= - poaibis arba sutampa */ >> %1
echo    C_nsubset,        // 505 /* C/ - nepoaibis */ >> %1
echo // >> %1
echo    C_in,             // 506 /* C_epsilon_var - priklauso */ >> %1
echo    C_notin,          // 507 /* C_epsilon_var_Slash - nepriklauso */ >> %1
echo    C_ni,             // 508 /* C_epsilon_var apsuktas - apima */ >> %1
echo // >> %1
echo    C_leftarr,        // 509 /* <-- */ >> %1
echo    C_rightarr,       // 510 /* --> */ >> %1
echo    C_leftrightarr,   // 511 /* <--> */ >> %1
echo    C_uparr,          // 512 /* ^| */ >> %1
echo    C_downarr,        // 513 /* |v */ >> %1
echo    C_updownarr,      // 514 /* ^|v */ >> %1
echo // >> %1
echo    C_Leftarr,        // 515 /* <== */ >> %1
echo    C_Rightarr,       // 516 /* ==> */ >> %1
echo    C_Leftrightarr,   // 517 /* <==> */ >> %1
echo    C_Uparr,          // 518 /* ^|| */ >> %1
echo    C_Downarr,        // 519 /* ||v */ >> %1
echo    C_Updownarr,      // 520 /* ^||v */ >> %1
echo // >> %1
echo    C_mid,            // 521 /* | */ >> %1
echo    C_paral,          // 522 /* || */ >> %1
echo // >> %1
echo    C_diamond,        // 523 /* tusciaviduris rombas */ >> %1
echo // >> %1
echo    C_Club,           // 524 /* giles */ >> %1
echo    C_Diamond,        // 525 /* bugnai, pilnaviduris rombas, C_bdiamond */ >> %1
echo    C_Heart,          // 526 /* cirvai sirdys */ >> %1
echo    C_Spade,          // 527 /* pikai lapai */ >> %1
echo // >> %1
echo    C_hyph,           // 528 /* hidden hyphenation sign ("\-" for TEX) */ // C_Dash >> %1
echo    C_break,          // 529 /* line break character, no \hfill */ >> %1
echo // >> %1
echo    C_a_Car,          // 530 /* av - laikinai, po to ismesti !!! */ >> %1
echo // >> %1
echo    C_euro,           // 531 /* C= euro piniginis vienetas !!! kelti prie pinigu */ >> %1
echo // >> %1
echo    C_deg,            // 532 /* degree - panasiai, kaip C_Ring, tik desineje */ >> %1
echo    C_micro,          // 533 /* mikro - panasiai, kaip C_my */ >> %1
echo    C_Ohm,            // 534 /* Ohm sign - panasiai, kaip C_Omega */ >> %1
echo    C_Angst,          // 535 /* Angstroem - C_A_Ring */ >> %1
echo // >> %1
echo    C_Horl,           // 536 /* horizontal line --- , C_h_b */ >> %1
echo // >> %1
echo    C_Dag,            // 537 /* Dagger +| (kryzius) */ >> %1
echo    C_Ddag,           // 538 /* Double dagger +|+ (Kestucio kryzius) */ >> %1
echo // >> %1
echo    C_ff,             // 539 /* ff ligature */ >> %1
echo    C_fi,             // 540 /* fi ligature */ >> %1
echo    C_fj,             // 541 /* fj ligature */ >> %1
echo    C_ffi,            // 542 /* ff ligature */ >> %1
echo    C_ffl,            // 543 /* ff ligature */ >> %1
echo    C_fl,             // 544 /* ff ligature */ >> %1
echo // >> %1
echo    C_and,            // 545 /* ^ logical and */ >> %1
echo    C_or,             // 546 /* V logical or */ >> %1
echo // >> %1
echo    C_fun,            // 547 /* f function of */ >> %1
echo // >> %1
echo    C_MinPl,          // 548 /* -+ minus plus */ >> %1
echo // >> %1
echo    C_EnDash,         // 549 /* -- - vidutinio ilgio bruksnys */ >> %1
echo    C_EmDash,         // 550 /* --- - ilgas bruksnys */ >> %1
echo // >> %1
echo    C_Cdots,          // 551 /* ... - daugtaskis per viduri */ >> %1
echo    C_WideTilde,      // 552 /* ~ didele tilde */ >> %1
echo // >> %1
echo    C_QemSpc,         // 553 /* 1/4 m space */ >> %1
echo    C_EnSpc,          // 554 /* n space */ >> %1
echo    C_EmSpc,          // 555 /* m space */ >> %1
echo    C_2emSpc,         // 556 /* 2 m space */ >> %1
echo // >> %1
echo    C_NewPar,         // 557 /* paragraph end control character */ >> %1
echo // >> %1
echo                      // ---------------------------- >> %1
echo                      // lithuanian accented letters >> %1
echo // >> %1
echo    C_Y_Grave,        // 558 // Y` >> %1
echo    C_y_Grave,        // 559 // y` >> %1
echo    C_E_Tilde,        // 560 // E~ >> %1
echo    C_e_Tilde,        // 561 // e~ >> %1
echo    C_I_Tilde,        // 562 // I~ >> %1
echo    C_i_Tilde,        // 563        // i~ >> %1
echo    C_U_Tilde,        // 564 // U~ >> %1
echo    C_u_Tilde,        // 565 // u~ >> %1
echo    C_Y_Tilde,        // 566 // Y~ >> %1
echo    C_y_Tilde,        // 567 // y~ >> %1
echo    C_L_Tilde,        // 568 // L~ >> %1
echo    C_l_Tilde,        // 569 // l~ >> %1
echo    C_M_Tilde,        // 570 // M~ >> %1
echo    C_m_Tilde,        // 571 // m~ >> %1
echo    C_R_Tilde,        // 572 // R~ >> %1
echo    C_r_Tilde,        // 573 // r~ >> %1
echo    C_A_Ogon_Acute,   // 574 >> %1
echo    C_a_Ogon_Acute,   // 575 >> %1
echo    C_E_Ogon_Acute,   // 576 >> %1
echo    C_e_Ogon_Acute,   // 577 >> %1
echo    C_E_Adot_Acute,   // 578 >> %1
echo    C_e_Adot_Acute,   // 579 >> %1
echo    C_I_Ogon_Acute,   // 580 >> %1
echo    C_i_Ogon_Acute,   // 581 >> %1
echo    C_U_Ogon_Acute,   // 582 >> %1
echo    C_u_Ogon_Acute,   // 583 >> %1
echo    C_U_Macr_Acute,   // 584 >> %1
echo    C_u_Macr_Acute,   // 585 >> %1
echo    C_A_Ogon_Grave,   // 586 >> %1
echo    C_a_Ogon_Grave,   // 587 >> %1
echo    C_E_Ogon_Grave,   // 588 >> %1
echo    C_e_Ogon_Grave,   // 589 >> %1
echo    C_E_Adot_Grave,   // 590 >> %1
echo    C_e_Adot_Grave,   // 591 >> %1
echo    C_I_Ogon_Grave,   // 592 >> %1
echo    C_i_Ogon_Grave,   // 593 >> %1
echo    C_U_Ogon_Grave,   // 594 >> %1
echo    C_u_Ogon_Grave,   // 595 >> %1
echo    C_U_Macr_Grave,   // 596 >> %1
echo    C_u_Macr_Grave,   // 597 >> %1
echo    C_A_Ogon_Tilde,   // 598 >> %1
echo    C_a_Ogon_Tilde,   // 599 >> %1
echo    C_E_Ogon_Tilde,   // 600 >> %1
echo    C_e_Ogon_Tilde,   // 601 >> %1
echo    C_E_Adot_Tilde,   // 602 >> %1
echo    C_e_Adot_Tilde,   // 603 >> %1
echo    C_I_Ogon_Tilde,   // 604 >> %1
echo    C_i_Ogon_Tilde,   // 605 >> %1
echo    C_U_Ogon_Tilde,   // 606 >> %1
echo    C_u_Ogon_Tilde,   // 607 >> %1
echo    C_U_Macr_Tilde,   // 608 >> %1
echo    C_u_Macr_Tilde,   // 609 >> %1
echo // >> %1
echo                      // ---------------------------- >> %1
echo                      // phonetic characters; vowels: >> %1
echo // >> %1
echo    C_ph_a,           // 610 // low back unrounded; a, open a; italic C_a >> %1
echo // >> %1
echo    C_ph_a_inv,       // 611 // low back rounded; oa; inverted italic C_a >> %1
echo // >> %1
echo    C_ph_a_sh,        // 612 // low-mid back unrounded; short a; inverted C_v >> %1
echo    C_ph_o_sh,        // 613 // low-mid back rounded; short o, open o; inverted C_c >> %1
echo // C_ph_o,           // mid back rounded?; o, closed o; C_o >> %1
echo // >> %1
echo    C_ph_u_sh,        // 614 // semi-high back rounded; short u, short open u; C_ypsilon >> %1
echo    C_ph_w_sh,        // 615 // semi-high back rounded; short u, short open u, obsolete; C_omega >> %1
echo // C_ph_u,           // semi-high central rounded?; u, closed u; C_u >> %1
echo // C_ph_u_soft,      // high central rounded; soft u, iu, german C_u_Diaer; C_y, >> %1
echo // >> %1
echo    C_ph_e_sh,        // 616 // low-mid front unrounded; short e, open e; C_epsilon >> %1
echo    C_ph_ae,          // 617 // low front unrounded?; e, open e; C_ae >> %1
echo // C_ph_e_cl,        // high central unrounded?; closed e, german e; C_e >> %1
echo    C_ph_e_sh_inv,    // 618 // low-mid central unrounded; hard e; inverted C_epsilon >> %1
echo    C_ph_e_inv,       // 619 // mid central unrounded; reduced e; inverted C_e >> %1
echo // >> %1
echo    C_ph_i_sh,        // 620 // semi-high front unrounded; short i, short open i; C_i without dot >> %1
echo // C_ph_i,           // high front unrounded?; i, closed i; C_i >> %1
echo // >> %1
echo                      // ---------------------------- >> %1
echo                      // phonetic characters; consonants: >> %1
echo // >> %1
echo    C_ph_sh,          // 621 // sh; C_f, C_int >> %1
echo    C_ph_zh,          // 622 // zh; C_3 >> %1
echo    C_ph_tsh,         // 623 // tsh; C_t C_f, C_t C_int >> %1
echo    C_ph_dzh,         // 624 // dzh; C_d C_3 >> %1
echo    C_ph_th_b,        // 625 // breath th; C_theta >> %1
echo    C_ph_th_v,        // 626 // voiced th; C_delta_Dash >> %1
echo    C_ph_ng,          // 627 // nasal g; C_eta >> %1
echo    C_ph_g,           // 628 // g; italic C_g >> %1
echo // >> %1
echo                      // ---------------------------- >> %1
echo                      // additional phonetic characters: >> %1
echo // >> %1
echo    C_ph_oe,          // 629 // high back rounded?; soft o, open soft o, io, german C_o_Diaer; C_oe, >> %1
echo    C_ph_o_slash,     // 630 // high back rounded?; soft o, closed soft o, io, german C_o_Diaer; C_o_Slash; "o/" >> %1
echo // >> %1
echo    C_ph_a_l,         // 631 // low back unrounded long; a long, open a long; a:, italic C_a C_Colon >> %1
echo    C_ph_e_inv_l,     // 632 // mid central unrounded long; reduced e long; e:, inverted C_e C_Colon >> %1
echo    C_ph_i_l,         // 633 // high front unrounded long?; i long, closed i long; i:, C_i C_Colon >> %1
echo    C_ph_o_l,         // 634 // low-mid back rounded long; o long, open o long; o:, inverted C_c C_Colon >> %1
echo    C_ph_u_l,         // 635 // ; u long; C_u C_Colon >> %1
echo // >> %1
echo    C_ph_a_n,         // 636 // low back unrounded nasal; a nasal, open a nasal; a~, italic C_a C_TildeAcc >> %1
echo    C_ph_a_str_n,     // 637 // ; straight a nasal; a~, C_a_Tilde >> %1
echo    C_ph_e_n,         // 638 // low-mid front unrounded nasal; short e nasal, open e nasal; e~, C_epsilon C_TildeAcc >> %1
echo    C_ph_oe_n,        // 639 // ; oe nasal; oe~, C_oe C_TildeAcc >> %1
echo    C_ph_o_n,         // 640 // low-mid back rounded nasal; open o nasal; o~, inverted C_c + C_TildeAcc >> %1
echo // >> %1
echo    C_ph_ch,          // 641 // german ch; C_c_Cedil >> %1
echo // >> %1
echo                      // ---------------------------- >> %1
echo                      // diphtongs >> %1
echo // >> %1
echo    C_ph_ai_d,        // 642 // C_a C_LigaLow C_i >> %1
echo    C_ph_ae_d,        // 643 // C_a C_LigaLow C_e >> %1
echo    C_ph_ao_d,        // 644 // C_a C_LigaLow C_o >> %1
echo    C_ph_au_d,        // 645 // C_a C_LigaLow C_u >> %1
echo    C_ph_ei_d,        // 646 // C_e C_LigaLow C_i >> %1
echo    C_ph_eu_d,        // 647 // C_e C_LigaLow C_u >> %1
echo    C_ph_ie_d,        // 648 // C_i C_LigaLow C_e >> %1
echo    C_ph_oe_d,        // 649 // C_ph_o_sh C_LigaLow C_ph_o_slash >> %1
echo    C_ph_oy_d,        // 650 // C_ph_o_sh C_LigaLow C_y >> %1
echo    C_ph_uo_d,        // 651 // C_u C_LigaLow C_o >> %1
echo // >> %1
echo                      // ---------------------------- >> %1
echo                      // breved phonetics >> %1
echo // >> %1
echo    C_ph_i_Brev,      // 652 // ; j; C_i_Brev >> %1
echo    C_ph_o_Brev,      // 653 //  C_o_Brev >> %1
echo    C_ph_u_Brev,      // 654 //  C_u_Brev >> %1
echo // >> %1
echo                      // liga accents (for diphtongs) >> %1
echo // >> %1
echo    C_LigaUp,         // 655 // lankelis virs dvieju raidziu >> %1
echo    C_LigaLow,        // 656 // lankelis po dviem raidem >> %1
echo // >> %1
echo    C_MidRing,        // 657 // mazas apskritimas viduryje (tusciaviduris bulletas - kaip C_Bpoint) >> %1
echo // >> %1
echo                      // phonetic accents >> %1
echo // >> %1
echo    C_ph_acc,         // 658 // C_Apost >> %1
echo    C_ph_acc_low,     // 659 // C_Comma >> %1
echo // >> %1
echo    C_square,         // 660 // tusciaviduris kvadratas viduryje >> %1
echo // >> %1
echo    C_male,           // 661 // vyr. lytis, male sex, mars, o^ >> %1
echo    C_female,         // 662 // mot. lytis, female sex, venus, o+ >> %1
echo // >> %1
echo    C_O_ring,         // 663 // Oo - mazas apskritimas O viduje >> %1
echo    C_O_dot,          // 664 // O. - taskas O viduje >> %1
echo // >> %1
echo    C_BigRing,        // 665 // didelis apskritimas, C_O >> %1
echo // >> %1
echo    C_longleftarr,    // 666 /* <---- */ >> %1
echo    C_longrightarr,   // 667 /* ----> */ >> %1
echo // >> %1
echo    C_smile,          // 668 // lankas, ~C_LigaLow >> %1
echo // >> %1
echo    C_box,            // 669 // pilnaviduris kvadratas viduryje, square bullet >> %1
echo // >> %1
echo                      // ---------------------------- >> %1
echo                      // DOS frames >> %1
echo // >> %1
echo    C_v_b,            // 670 // vert; ne DOS-e - C_Vertl >> %1
echo    C_h_b,            // 671 // hor; ne DOS-e - C_Horl >> %1
echo    C_vh_b,           // 672 // vert hor >> %1
echo    C_vl_b,           // 673 // vert left >> %1
echo    C_vr_b,           // 674 // vert right >> %1
echo    C_hu_b,           // 675 // hor up >> %1
echo    C_hd_b,           // 676 // hor down >> %1
echo    C_ul_b,           // 677 // up left >> %1
echo    C_dl_b,           // 678 // down left >> %1
echo    C_ur_b,           // 679 // up right >> %1
echo    C_dr_b,           // 680 // down right >> %1
echo // >> %1
echo    C_2v_b,           // 681 // double vert; C_paral >> %1
echo    C_2h_b,           // 682 // double hor >> %1
echo    C_2v2h_b,         // 683 // double vert double hor >> %1
echo    C_2v2l_b,         // 684 // double vert double left >> %1
echo    C_2v2r_b,         // 685 // double vert double right >> %1
echo    C_2h2u_b,         // 686 // double hor double up >> %1
echo    C_2h2d_b,         // 687 // double hor double down >> %1
echo    C_2u2l_b,         // 688 // double up double left >> %1
echo    C_2d2l_b,         // 689 // double down double left >> %1
echo    C_2u2r_b,         // 690 // double up double right >> %1
echo    C_2d2r_b,         // 691 // double down double right >> %1
echo // >> %1
echo    C_2vh_b,          // 692 // double vert hor >> %1
echo    C_2vl_b,          // 693 // double vert left >> %1
echo    C_2vr_b,          // 694 // double vert right >> %1
echo    C_h2u_b,          // 695 // hor double up >> %1
echo    C_h2d_b,          // 696 // hor double down >> %1
echo    C_2ul_b,          // 697 // double up left >> %1
echo    C_2dl_b,          // 698 // double down left >> %1
echo    C_2ur_b,          // 699 // double up right >> %1
echo    C_2dr_b,          // 700 // double down right >> %1
echo // >> %1
echo    C_v2h_b,          // 701 // vert double hor >> %1
echo    C_v2l_b,          // 702 // vert double left >> %1
echo    C_v2r_b,          // 703 // vert double right >> %1
echo    C_2hu_b,          // 704 // double hor up >> %1
echo    C_2hd_b,          // 705 // double hor down >> %1
echo    C_u2l_b,          // 706 // up double left >> %1
echo    C_d2l_b,          // 707 // down double left >> %1
echo    C_u2r_b,          // 708 // up double right >> %1
echo    C_d2r_b,          // 709 // down double right >> %1
echo // >> %1
echo    C_block,          // 710 // pilnaviduris kvadratas per visa laukeli >> %1
echo    C_dgrblk,         // 711 // tamsiai pilkas ---//--- (75% shaded) >> %1
echo    C_grblk,          // 712 // pilkas ---//--- (50% shaded) >> %1
echo    C_lgrblk,         // 713 // sviesiai pilkas ---//--- (25% shaded) >> %1
echo    C_uphblk,         // 714 // pilnaviduris staciakampis per puse laukelio virsuje >> %1
echo    C_dnhblk,         // 715 // ---//--- apacioje >> %1
echo    C_lthblk,         // 716 // ---//--- kaireje >> %1
echo    C_rthblk,         // 717 // ---//--- desineje >> %1
echo // >> %1
echo    C_utrif,          // 718 // pilnaviduris lygiakrastis trikampis smaigaliu i virsu, MS Word UTF16 >> %1
echo    C_dtrif,          // 719 // pilnaviduris trikampis zemyn, MS Word UTF16 >> %1
echo    C_ltrif,          // 720 // pilnaviduris trikampis i kaire; MS Word UTF16, IExplorer ir Netscape C_ltri >> %1
echo    C_rtrif,          // 721 // pilnaviduris trikampis i desine; MS Word UTF16, IExplorer ir Netscape C_rtri >> %1
echo // >> %1
echo                      // ---------------------------- >> %1
echo    C_ph_uu_sh,       // 722 // phonetics: semi-high back rounded; short u, short open u; inverted C_Omega >> %1
echo // >> %1
echo    C_hhyph,          // 723 // hard hyphen - zodzio kelimas per prievarta "-\break" // C_hyph, C_Dash >> %1
echo    C_sbreak,         // 724 // soft break \lastwordinpar{5}{...} iki pastraipos (lizdo) pabaigos >> %1
echo    C_hSpc,           // 725 // hard space - technical space after TEX commands - do not process >> %1
echo    C_hbreak,         // 726 // break su \hfill, xmlsty keiciamas is C_Cr ("\r"), C_break >> %1
echo    C_lSpc,           // 727 // last space - space, to be changed to C_NBSP after LAST_WORD_LEN >> %1
echo    C_hlSpc,          // 728 // hard last space - C_hSpc, to be changed to C_NBSP after LAST_WORD_LEN >> %1
echo // >> %1
echo    C_utrif_rtf,      // 729 // pilnaviduris lygiakrastis trikampis smaigaliu i virus, MS Word RTF >> %1
echo    C_dtrif_rtf,      // 730 // pilnaviduris trikampis zemyn, MS Word RTF >> %1
echo    C_ltrif_rtf,      // 731 // pilnaviduris trikampis i kaire, MS Word RTF >> %1
echo    C_rtrif_rtf,      // 732 // pilnaviduris trikampis i desine, MS Word RTF >> %1
echo // >> %1
echo // erdvines rodykles - zr. mcm_src.48d mac_p.rtf lizdas 2231 >> %1
echo    C_3DTopLightLeftArrowHead,    // 733 >> %1
echo    C_3DBotLightLeftArrowHead,    // 734 >> %1
echo    C_3DTopLightRightArrowHead,   // 735 >> %1
echo    C_3DBotLightRightArrowHead,   // 736 >> %1
echo    C_3DLeftLightUpArrowHead,     // 737 >> %1
echo    C_3DRightLightUpArrowHead,    // 738 >> %1
echo    C_3DLeftLightDownArrowHead,   // 739 >> %1
echo    C_3DRightLightDownArrowHead,  // 740 >> %1
echo // >> %1
echo    C_MinusMath,      // 741   // C_Dash >> %1
echo // >> %1
echo    C_ZeroWidthSpace, // 742   // C_Spc >> %1
echo // >> %1
echo    C_ph_glot_stop,   // 743   // phonetics: glottal stop, ~ C_Quest be tasko >> %1
echo // >> %1
echo                      // --------------------------- >> %1
echo                      // nekombinaciniai diakritai >> %1
echo // >> %1
echo    C_AcuteNcomb,     // 744   // nekombinacinis desininis kirtis (C_Acute, C_Apost) >> %1
echo    C_CedilNcomb,     // 745   // nekombinacine cedilla (C_Cedil) >> %1
echo    C_MacrNcomb,      // 746   // nekombinacinis bruksnys virsuje (C_Macr) >> %1
echo // >> %1
echo                      // --------------------------- >> %1
echo // >> %1
echo    C_DollNctrl,      // 747   // nevaldantis dolerio zenklas (C_Doll); TEX'e yra atitikmuo TX_SP_Doll >> %1
echo // >> %1
echo    C_OgonNcomb,      // 748   // nekombinacinis nosines diakritas (C_Ogon) >> %1
echo // >> %1
echo    C_No,             // 749   // rusiskas numerio zenklas No >> %1
echo // >> %1
echo                      // --------------------------- >> %1
echo                      // nekombinaciniai diakritai >> %1
echo // >> %1
echo    C_CarNcomb,       // 750   // nekombinacinis Caron (Pauksciukas) (C_Car) >> %1
echo    C_DiaerNcomb,     // 751   // nekombinacinis umlautas (C_Diaer) >> %1
echo    C_TildeNcomb,     // 752   // nekombinacinis tildes diakritas, galmetu C_Tilde, bet TEX-e storesne ir per viduri, o reikia pakeltos; C_TildeAcc >> %1
echo // >> %1
echo                      // --------------------------- >> %1
echo // >> %1
echo    C_utri,           // 753   // tusciaviduris lygiakrastis trikampis smaigaliu i virsu >> %1
echo    C_dtri,           // 754   // tusciaviduris trikampis zemyn >> %1
echo    C_ltri,           // 755   // tusciaviduris trikampis i kaire; MS Word UTF16, IExplorer ir Netscape pilnaviduris >> %1
echo    C_rtri,           // 756   // tusciaviduris trikampis i desine; MS Word UTF16, IExplorer ir Netscape pilnaviduris >> %1
echo // >> %1
echo // ---------------------------- >> %1
echo    C_Oline,          // 757   // kombinacinis matematinis diakritas - bruksnys virs raides, C_Macr >> %1
echo  >> %1
echo    C_R_Oline,        // 758   // R su bruksniu, C_R_Macr >> %1
echo    C_X_Oline,        // 759   // X su bruksniu, C_X_Macr >> %1
echo // >> %1
echo    C_leqslant,       // 760   /* <= - maziau arba lygu, lygybe lygiagreti su < */ >> %1
echo    C_geqslant,       // 761   /* >= - daugiau arba lygu, lygybe lygiagreti su > */ >> %1
echo // >> %1
echo    C_i_Grave_Dotless, // 762 // C_i_Grave, // i` >> %1
echo    C_i_Acute_Dotless, // 763 // C_i_Acute, // i' >> %1
echo    C_i_Tilde_Dotless, // 764 // C_i_Tilde, // i~ >> %1
echo // >> %1
echo //------------------------- accented cyrillic >> %1
echo    C_A_Cyr_Acute,    // 765 >> %1
echo    C_E_Cyr_Acute,    // 766 >> %1
echo    C_I_Cyr_Acute,    // 767 >> %1
echo    C_O_Cyr_Acute,    // 768 >> %1
echo    C_U_Cyr_Acute,    // 769 >> %1
echo    C_Y_Cyr_Acute,    // 770 >> %1
echo    C_Ee_Cyr_Acute,   // 771 >> %1
echo    C_Yu_Cyr_Acute,   // 772 >> %1
echo    C_Ya_Cyr_Acute,   // 773 >> %1
echo // >> %1
echo    C_a_Cyr_Acute,    // 774 >> %1
echo    C_e_Cyr_Acute,    // 775 >> %1
echo    C_i_Cyr_Acute,    // 776 >> %1
echo    C_o_Cyr_Acute,    // 777 >> %1
echo    C_u_Cyr_Acute,    // 778 >> %1
echo    C_y_Cyr_Acute,    // 779 >> %1
echo    C_ee_Cyr_Acute,   // 780 >> %1
echo    C_yu_Cyr_Acute,   // 781 >> %1
echo    C_ya_Cyr_Acute,   // 782 >> %1
echo // >> %1
echo    C_NullSpc,        // 783 /* null width space, skirtuku atskyriklis, tarpu valgytojas */ >> %1
echo // >> %1
echo    C_Dash_Diaer,     // 784   dash su umlautu -" >> %1
echo // >> %1
echo    C_bdiamond,       // 785 /* pilnaviduris rombas, C_Diamond */ >> %1
echo // >> %1
echo    C_DegCels,        // 786 /* degree Celsius - celsijaus laipsniai, C_deg C_C */ >> %1
echo // >> %1
echo    C_hBpoint,        // 787 /* bullet, didelis taskas vidury */ // tiems atvejams, kai C_Bpoint naudojamas homonimø identifikavimui (DOUBLE_ENTRIES_KPCHAR)  >> %1
echo // >> %1
echo // ----------------------- old style cyrillic >> %1
echo    C_Fita_Cyr,       // 788 >> %1
echo    C_fita_Cyr,       // 789 >> %1
echo    C_Yat_Cyr,        // 790 >> %1
echo    C_yat_Cyr,        // 791 >> %1
echo  >> %1
echo    C_checkmark,      // 792 // varnelë paþymëjimui >> %1
echo // >> %1
echo                      // ---------------------------- >> %1
echo                      // nekombinaciniai diakritai >> %1
echo // >> %1
echo    C_prim_Ncomb,     // 793 /* strichas prie raides (C_Acute, C_Apost; C_AcuteNcomb) */ >> %1
echo    C_dprim_Ncomb,    // 794 /* du strichai (C_Dacut) */ >> %1

