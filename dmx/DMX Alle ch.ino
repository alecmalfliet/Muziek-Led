#include <DMXSerial.h>



int ch1;
int ch2;
int ch3;
int ch4;
int ch5;
int ch6;
int ch7;
int ch8;
int ch9;

int ch11;
int ch12;
int ch13;
int ch14;
int ch15;
int ch16;
int ch17;
int ch18;
int ch19;

int ch21;
int ch22;
int ch23;
int ch24;
int ch25;
int ch26;
int ch27;
int ch28;
int ch29;

int ch31;
int ch32;
int ch33;
int ch34;
int ch35;
int ch36;
int ch37;
int ch38;
int ch39;

int ch41;
int ch42;
int ch43;
int ch44;
int ch45;
int ch46;
int ch47;
int ch48;
int ch49;

int ch51;
int ch52;
int ch53;
int ch54;
int ch55;
int ch56;
int ch57;
int ch58;
int ch59;

int ch61;
int ch62;
int ch63;
int ch64;
int ch65;
int ch66;
int ch67;
int ch68;
int ch69;

int ch71;
int ch72;
int ch73;
int ch74;
int ch75;
int ch76;
int ch77;
int ch78;
int ch79;

int ch81;
int ch82;
int ch83;
int ch84;
int ch85;
int ch86;
int ch87;
int ch88;
int ch89;

int ch91;
int ch92;
int ch93;
int ch94;
int ch95;
int ch96;
int ch97;
int ch98;
int ch99;

int ch101;
int ch102;
int ch103;
int ch104;
int ch105;
int ch106;
int ch107;
int ch108;
int ch109;

int ch111;
int ch112;
int ch113;
int ch114;
int ch115;
int ch116;
int ch117;
int ch118;
int ch119;

int ch121;
int ch122;
int ch123;
int ch124;
int ch125;
int ch126;
int ch127;
int ch128;
int ch129;

int ch131;
int ch132;
int ch133;
int ch134;
int ch135;
int ch136;
int ch137;
int ch138;
int ch139;

int ch141;
int ch142;
int ch143;
int ch144;
int ch145;
int ch146;
int ch147;
int ch148;
int ch149;

int ch151;
int ch152;
int ch153;
int ch154;
int ch155;
int ch156;
int ch157;
int ch158;
int ch159;

int ch161;
int ch162;
int ch163;
int ch164;
int ch165;
int ch166;
int ch167;
int ch168;
int ch169;

int ch171;
int ch172;
int ch173;
int ch174;
int ch175;
int ch176;
int ch177;
int ch178;
int ch179;

int ch181;
int ch182;
int ch183;
int ch184;
int ch185;
int ch186;
int ch187;
int ch188;
int ch189;

int ch191;
int ch192;

void setup () {
  DMXSerial.init(DMXReceiver);
   
}


void loop() {
  unsigned long lastPacket = DMXSerial.noDataSince();
  
  if (lastPacket < 5000) {
    ch1 = DMXSerial.read(1);
    ch2 = DMXSerial.read(2);
    ch3 = DMXSerial.read(3);
    ch4 = DMXSerial.read(4);
    ch5 = DMXSerial.read(5);
    ch6 = DMXSerial.read(6);
    ch7 = DMXSerial.read(7);
    ch8 = DMXSerial.read(8);
    ch9 = DMXSerial.read(9);

    ch11 = DMXSerial.read(11);
    ch12 = DMXSerial.read(12);
    ch13 = DMXSerial.read(13);
    ch14 = DMXSerial.read(14);
    ch15 = DMXSerial.read(15);
    ch16 = DMXSerial.read(16);
    ch17 = DMXSerial.read(17);
    ch18 = DMXSerial.read(18);
    ch19 = DMXSerial.read(19);

    ch21 = DMXSerial.read(21);
    ch22 = DMXSerial.read(22);
    ch23 = DMXSerial.read(23);
    ch24 = DMXSerial.read(24);
    ch25 = DMXSerial.read(25);
    ch26 = DMXSerial.read(26);
    ch27 = DMXSerial.read(27);
    ch28 = DMXSerial.read(28);
    ch29 = DMXSerial.read(29);

    ch31 = DMXSerial.read(31);
    ch32 = DMXSerial.read(32);
    ch33 = DMXSerial.read(33);
    ch34 = DMXSerial.read(34);
    ch35 = DMXSerial.read(35);
    ch36 = DMXSerial.read(36);
    ch37 = DMXSerial.read(37);
    ch38 = DMXSerial.read(38);
    ch39 = DMXSerial.read(39);

    ch41 = DMXSerial.read(41);
    ch42 = DMXSerial.read(42);
    ch43 = DMXSerial.read(43);
    ch44 = DMXSerial.read(44);
    ch45 = DMXSerial.read(45);
    ch46 = DMXSerial.read(46);
    ch47 = DMXSerial.read(47);
    ch48 = DMXSerial.read(48);
    ch49 = DMXSerial.read(49);

    ch51 = DMXSerial.read(51);
    ch52 = DMXSerial.read(52);
    ch53 = DMXSerial.read(53);
    ch54 = DMXSerial.read(54);
    ch55 = DMXSerial.read(55);
    ch56 = DMXSerial.read(56);
    ch57 = DMXSerial.read(57);
    ch58 = DMXSerial.read(58);
    ch59 = DMXSerial.read(59);

    ch61 = DMXSerial.read(61);
    ch62 = DMXSerial.read(62);
    ch63 = DMXSerial.read(63);
    ch64 = DMXSerial.read(64);
    ch65 = DMXSerial.read(65);
    ch66 = DMXSerial.read(66);
    ch67 = DMXSerial.read(67);
    ch68 = DMXSerial.read(68);
    ch69 = DMXSerial.read(69);

    ch71 = DMXSerial.read(71);
    ch72 = DMXSerial.read(72);
    ch73 = DMXSerial.read(73);
    ch74 = DMXSerial.read(74);
    ch75 = DMXSerial.read(75);
    ch76 = DMXSerial.read(76);
    ch77 = DMXSerial.read(77);
    ch78 = DMXSerial.read(78);
    ch79 = DMXSerial.read(79);

    ch81 = DMXSerial.read(81);
    ch82 = DMXSerial.read(82);
    ch83 = DMXSerial.read(83);
    ch84 = DMXSerial.read(84);
    ch85 = DMXSerial.read(85);
    ch86 = DMXSerial.read(86);
    ch87 = DMXSerial.read(87);
    ch88 = DMXSerial.read(88);
    ch89 = DMXSerial.read(89);
    
    ch91 = DMXSerial.read(91);
    ch92 = DMXSerial.read(92);
    ch93 = DMXSerial.read(93);
    ch94 = DMXSerial.read(94);
    ch95 = DMXSerial.read(95);
    ch96 = DMXSerial.read(96);
    ch97 = DMXSerial.read(97);
    ch98 = DMXSerial.read(98);
    ch99 = DMXSerial.read(99);

    ch101 = DMXSerial.read(101);
    ch102 = DMXSerial.read(102);
    ch103 = DMXSerial.read(103);
    ch104 = DMXSerial.read(104);
    ch105 = DMXSerial.read(105);
    ch106 = DMXSerial.read(106);
    ch107 = DMXSerial.read(107);
    ch108 = DMXSerial.read(108);
    ch109 = DMXSerial.read(109);

    ch111 = DMXSerial.read(111);
    ch112 = DMXSerial.read(112);
    ch113 = DMXSerial.read(113);
    ch114 = DMXSerial.read(114);
    ch115 = DMXSerial.read(115);
    ch116 = DMXSerial.read(116);
    ch117 = DMXSerial.read(117);
    ch118 = DMXSerial.read(118);
    ch119 = DMXSerial.read(119);

    ch121 = DMXSerial.read(121);
    ch122 = DMXSerial.read(122);
    ch123 = DMXSerial.read(123);
    ch124 = DMXSerial.read(124);
    ch125 = DMXSerial.read(125);
    ch126 = DMXSerial.read(126);
    ch127 = DMXSerial.read(127);
    ch128 = DMXSerial.read(128);
    ch129 = DMXSerial.read(129);

    ch131 = DMXSerial.read(131);
    ch132 = DMXSerial.read(132);
    ch133 = DMXSerial.read(133);
    ch134 = DMXSerial.read(134);
    ch135 = DMXSerial.read(135);
    ch136 = DMXSerial.read(136);
    ch137 = DMXSerial.read(137);
    ch138 = DMXSerial.read(138);
    ch139 = DMXSerial.read(139);

    ch141 = DMXSerial.read(141);
    ch142 = DMXSerial.read(142);
    ch143 = DMXSerial.read(143);
    ch144 = DMXSerial.read(144);
    ch145 = DMXSerial.read(145);
    ch146 = DMXSerial.read(146);
    ch147 = DMXSerial.read(147);
    ch148 = DMXSerial.read(148);
    ch149 = DMXSerial.read(149);

    ch151 = DMXSerial.read(151);
    ch152 = DMXSerial.read(152);
    ch153 = DMXSerial.read(153);
    ch154 = DMXSerial.read(154);
    ch155 = DMXSerial.read(155);
    ch156 = DMXSerial.read(156);
    ch157 = DMXSerial.read(157);
    ch158 = DMXSerial.read(158);
    ch159 = DMXSerial.read(159);

    ch161 = DMXSerial.read(161);
    ch162 = DMXSerial.read(162);
    ch163 = DMXSerial.read(163);
    ch164 = DMXSerial.read(164);
    ch165 = DMXSerial.read(165);
    ch166 = DMXSerial.read(166);
    ch167 = DMXSerial.read(167);
    ch168 = DMXSerial.read(168);
    ch169 = DMXSerial.read(169);

    ch171 = DMXSerial.read(171);
    ch172 = DMXSerial.read(172);
    ch173 = DMXSerial.read(173);
    ch174 = DMXSerial.read(174);
    ch175 = DMXSerial.read(175);
    ch176 = DMXSerial.read(176);
    ch177 = DMXSerial.read(177);
    ch178 = DMXSerial.read(178);
    ch179 = DMXSerial.read(179);

    ch181 = DMXSerial.read(181);
    ch182 = DMXSerial.read(182);
    ch183 = DMXSerial.read(183);
    ch184 = DMXSerial.read(184);
    ch185 = DMXSerial.read(185);
    ch186 = DMXSerial.read(186);
    ch187 = DMXSerial.read(187);
    ch188 = DMXSerial.read(188);
    ch189 = DMXSerial.read(189);
    
    ch191 = DMXSerial.read(191);
    ch192 = DMXSerial.read(192);

  } else {
      // als er geen DMX aan wezig is
  }
}
