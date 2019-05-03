// ******************************
// by Lemmy
// ******************************

const bool alpha[][8][5] = {
  { { 0, 0, 0, 0, 0, }, // SP 32
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 0, 0, 0, 0, }, // ! 33
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 0, 1, 0, 0, }, // " 34
    { 1, 0, 1, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 1, 0, 1, 0, }, // # 35
    { 0, 1, 0, 1, 0, },
    { 1, 1, 1, 1, 1, },
    { 0, 1, 0, 1, 0, },
    { 1, 1, 1, 1, 1, },
    { 0, 1, 0, 1, 0, },
    { 0, 1, 0, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 1, 0, 0, }, // $ 36
    { 0, 1, 1, 1, 1, },
    { 1, 0, 1, 0, 0, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 1, 0, 1, },
    { 1, 1, 1, 1, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // % 37
    { 1, 1, 0, 0, 1, },
    { 1, 1, 0, 1, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 1, 0, 1, 1, },
    { 1, 0, 0, 1, 1, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 1, 1, 0, }, // & 38
    { 0, 1, 0, 1, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 1, 0, 1, 0, },
    { 1, 0, 0, 1, 1, },
    { 1, 0, 0, 1, 0, },
    { 0, 1, 1, 0, 1, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 0, 0, 0, 0, }, // ' 39
    { 1, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 1, 0, 0, }, // ( 40
    { 0, 1, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 0, 0, 0, 0, }, // ) 41
    { 0, 1, 0, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 1, 0, 0, }, // * 42
    { 1, 0, 1, 0, 1, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 1, 1, 1, 0, },
    { 1, 0, 1, 0, 1, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // + 43
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 1, 1, 1, 1, 1, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // , 44
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 1, 1, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 1, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // - 45
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 1, 1, 1, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // . 46
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 1, 1, 0, 0, 0, },
    { 1, 1, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 1, }, // / 47
    { 0, 0, 0, 1, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 1, 1, 1, 0, }, // 0 48
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 1, 1, },
    { 1, 0, 1, 0, 1, },
    { 1, 1, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 1, 0, 0, }, // 1 49
    { 0, 1, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 1, 1, 1, 1, 1, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 1, 1, 1, 0, }, // 2 50
    { 1, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 1, },
    { 0, 0, 0, 1, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 1, 1, 1, 1, 1, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 1, 1, 1, 0, }, // 3 51
    { 1, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 1, },
    { 0, 0, 1, 1, 0, },
    { 0, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 1, 1, 0, }, // 4 52
    { 0, 1, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 1, 1, 1, 1, },
    { 0, 0, 0, 1, 0, },
    { 0, 0, 0, 1, 0, },
    { 0, 0, 1, 1, 1, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 1, 1, 1, 1, }, // 5 53
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 1, 1, 1, 0, }, // 6 54
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 0, },
    { 1, 1, 1, 1, 0, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 1, 1, 1, 1, }, // 7 55
    { 0, 0, 0, 0, 1, },
    { 0, 0, 0, 1, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 1, 1, 1, 0, }, // 8 56
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 1, 1, 1, 0, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 1, 1, 1, 0, }, // 9 57
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 1, 1, 1, 1, },
    { 0, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // : 58
    { 1, 1, 0, 0, 0, },
    { 1, 1, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 1, 1, 0, 0, 0, },
    { 1, 1, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // ; 59
    { 0, 0, 0, 0, 0, },
    { 1, 1, 0, 0, 0, },
    { 1, 1, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 1, 1, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 1, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 1, 0, }, // < 60
    { 0, 0, 1, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 0, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // = 61
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 1, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 0, },
    { 1, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 0, 0, 0, 0, }, // > 62
    { 0, 1, 0, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 0, 1, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 1, 1, 1, 0, }, // ? 63
    { 1, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 1, },
    { 0, 0, 0, 1, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 1, 1, 1, 0, }, // @ 64
    { 1, 0, 0, 0, 1, },
    { 1, 0, 1, 1, 1, },
    { 1, 0, 1, 0, 1, },
    { 1, 0, 1, 1, 1, },
    { 1, 0, 0, 0, 0, },
    { 1, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 1, 1, 1, 0, }, // A 65
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 1, 1, 1, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 0, }
  },
  {
    { 1, 1, 1, 1, 0, }, // B 66
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 1, 1, 1, 0, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 1, 1, 1, 0, }, // C 67
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 1, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 1, 1, 1, 0, }, // D 68
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 1, 1, 1, 1, }, // E 69
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 1, 1, 1, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 1, 1, 1, 1, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 1, 1, 1, 1, }, // F 70
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 1, 1, 1, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 1, 1, 1, 0, }, // G 71
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 1, 1, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 0, 0, 0, 1, }, // H 72
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 1, 1, 1, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 1, 1, 1, 1, }, // I 73
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 1, 1, 1, 1, 1, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 1, 1, 1, }, // J 74
    { 0, 0, 0, 1, 0, },
    { 0, 0, 0, 1, 0, },
    { 0, 0, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 0, 1, 1, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 0, 0, 0, 1, }, // K 75
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 1, 0, },
    { 1, 1, 1, 0, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 0, 0, 0, 0, }, // L 76
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 1, 1, 1, 1, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 0, 0, 0, 1, }, // M 77
    { 1, 1, 0, 1, 1, },
    { 1, 0, 1, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 0, 0, 0, 1, }, // N 78
    { 1, 1, 0, 0, 1, },
    { 1, 0, 1, 0, 1, },
    { 1, 0, 1, 0, 1, },
    { 1, 0, 0, 1, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 1, 1, 1, 0, }, // O 79
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 1, 1, 1, 0, }, // P 80
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 1, 1, 1, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 1, 1, 1, 0, }, // Q 81
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 0, 1, 1, }
  },
  { { 1, 1, 1, 1, 0, }, // R 82
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 1, 1, 1, 0, },
    { 1, 0, 1, 0, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 1, 1, 1, 0, }, // S 83
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 0, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 1, 1, 1, 1, }, // T 84
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 0, 0, 0, 1, }, // U 85
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 0, 0, 0, 1, }, // V 86
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 1, 0, 1, 0, },
    { 0, 1, 0, 1, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 0, 0, 0, 1, }, // W 87
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 1, 0, 1, },
    { 0, 1, 1, 1, 0, },
    { 0, 1, 1, 1, 0, },
    { 0, 1, 0, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 0, 0, 0, 1, }, // X 88
    { 1, 0, 0, 0, 1, },
    { 0, 1, 0, 1, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 1, 0, 1, 0, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 0, 0, 0, 1, }, // Y 89
    { 1, 0, 0, 0, 1, },
    { 0, 1, 0, 1, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 1, 1, 1, 1, }, // Z 90
    { 0, 0, 0, 0, 1, },
    { 0, 0, 0, 1, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 1, 1, 1, 1, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 1, 1, 0, 0, }, // [ 91
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 1, 1, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 0, 0, 0, 0, }, // \ 92
    { 0, 1, 0, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 0, 1, 0, },
    { 0, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 1, 1, 0, 0, }, // ] 93
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 1, 1, 1, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 1, 0, 0, }, // ^ 94
    { 0, 1, 0, 1, 0, },
    { 1, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // _ 95
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 1, 1, 1, 1, 1, }
  },
  { { 1, 0, 0, 0, 0, }, // ` 96
    { 0, 1, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // a 97
    { 0, 0, 0, 0, 0, },
    { 1, 1, 1, 0, 0, },
    { 0, 0, 0, 1, 0, },
    { 0, 1, 1, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 0, 1, 1, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 0, 0, 0, 0, }, // b 98
    { 1, 0, 0, 0, 0, },
    { 1, 1, 1, 0, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 1, 1, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // c 99
    { 0, 0, 0, 0, 0, },
    { 0, 1, 1, 1, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 1, 0, }, // d 100
    { 0, 0, 0, 1, 0, },
    { 0, 1, 1, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 0, 1, 1, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // e 101
    { 0, 0, 0, 0, 0, },
    { 0, 1, 1, 0, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 1, 1, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 1, 0, 0, }, // f 102
    { 0, 1, 0, 1, 0, },
    { 0, 1, 0, 0, 0, },
    { 1, 1, 1, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // g 103
    { 0, 0, 0, 0, 0, },
    { 0, 1, 1, 0, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 0, 1, 0, },
    { 0, 1, 1, 0, 0, }
  },
  { { 1, 0, 0, 0, 0, }, // h 104
    { 1, 0, 0, 0, 0, },
    { 1, 1, 1, 0, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // i 105
    { 1, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // j 106
    { 0, 0, 1, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 1, 1, 0, 0, 0, }
  },
  { { 1, 0, 0, 0, 0, }, // k 107
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 1, 0, 0, },
    { 1, 1, 0, 0, 0, },
    { 1, 0, 1, 0, 0, },
    { 1, 0, 0, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 1, 0, 0, 0, }, // l 108
    { 0, 1, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // m 109
    { 0, 0, 0, 0, 0, },
    { 0, 1, 0, 1, 0, },
    { 1, 0, 1, 0, 1, },
    { 1, 0, 1, 0, 1, },
    { 1, 0, 1, 0, 1, },
    { 1, 0, 1, 0, 1, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // n 110
    { 0, 0, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 1, 0, 1, 0, 0, },
    { 1, 0, 1, 0, 0, },
    { 1, 0, 1, 0, 0, },
    { 1, 0, 1, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // o 111
    { 0, 0, 0, 0, 0, },
    { 0, 1, 1, 0, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 0, 1, 1, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // p 112
    { 0, 0, 0, 0, 0, },
    { 0, 1, 1, 0, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 1, 1, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // q 113
    { 0, 0, 0, 0, 0, },
    { 0, 1, 1, 0, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 0, 1, 0, },
    { 0, 0, 0, 1, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // r 114
    { 0, 0, 0, 0, 0, },
    { 1, 0, 1, 1, 0, },
    { 1, 1, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // s 115
    { 0, 0, 0, 0, 0, },
    { 0, 1, 1, 1, 0, },
    { 1, 0, 0, 0, 0, },
    { 0, 1, 1, 0, 0, },
    { 0, 0, 0, 1, 0, },
    { 1, 1, 1, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // t 116
    { 0, 1, 0, 0, 0, },
    { 1, 1, 1, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // u 117
    { 0, 0, 0, 0, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 0, 1, 1, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // v 118
    { 0, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 0, 1, 0, 1, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // w 119
    { 0, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 0, 0, 1, },
    { 1, 0, 1, 0, 1, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // x 120
    { 0, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 1, },
    { 0, 1, 0, 1, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 1, 0, 1, 0, },
    { 1, 0, 0, 0, 1, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // y 121
    { 0, 0, 0, 0, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 1, 0, 0, 1, 0, },
    { 0, 1, 1, 1, 0, },
    { 0, 0, 0, 1, 0, },
    { 1, 1, 1, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // z 122
    { 0, 0, 0, 0, 0, },
    { 1, 1, 1, 1, 0, },
    { 0, 0, 0, 1, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 1, 1, 1, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 1, 1, 0, }, // { 123
    { 0, 1, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 0, 0, 1, 1, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 0, 0, 0, 0, }, // | 124
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 1, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 1, 0, 0, 0, }, // } 125
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 0, 1, 0, },
    { 0, 0, 1, 0, 0, },
    { 0, 0, 1, 0, 0, },
    { 1, 1, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 0, 0, 0, 0, 0, }, // ~ 126
    { 0, 0, 0, 0, 0, },
    { 0, 1, 0, 0, 0, },
    { 1, 0, 1, 0, 1, },
    { 0, 0, 0, 1, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, }
  },
  { { 1, 1, 1, 1, 1, }, // DEL 127
    { 1, 1, 1, 1, 1, },
    { 1, 1, 1, 1, 1, },
    { 1, 1, 1, 1, 1, },
    { 1, 1, 1, 1, 1, },
    { 1, 1, 1, 1, 1, },
    { 1, 1, 1, 1, 1, },
    { 0, 0, 0, 0, 0, }
  }
};

// **************************************************
String alpha_transformhtml(String txt) {
  txt.replace("+", " ");
  txt.replace("%21", "!");
  txt.replace("%22", "\"");
  txt.replace("%23", "#");
  txt.replace("%24", "$");
  txt.replace("%25", "%");
  txt.replace("%26", "&");
  txt.replace("%27", "'");
  txt.replace("%28", "(");
  txt.replace("%29", ")");
  txt.replace("%2A", "*");
  txt.replace("%2B", "+");
  txt.replace("%2C", ",");
  txt.replace("%2D", "-");
  txt.replace("%2E", ".");
  txt.replace("%2F", "/");
  txt.replace("%3A", ":");
  txt.replace("%3B", ";");
  txt.replace("%3C", "<");
  txt.replace("%3D", "=");
  txt.replace("%3E", ">");
  txt.replace("%3F", "?");
  txt.replace("%40", "@");
  txt.replace("%5B", "[");
  txt.replace("%5C", "\\");
  txt.replace("%5D", "]");
  txt.replace("%5E", "^");
  txt.replace("%5F", "_");
  txt.replace("%60", "`");
  txt.replace("%7B", "{");
  txt.replace("%7C", "|");
  txt.replace("%7D", "}");
  txt.replace("%7F", "~");
  txt.replace("%E0", "a");
  txt.replace("%E1", "a");
  txt.replace("%E2", "a");
  txt.replace("%E3", "a");
  txt.replace("%E4", "a");
  txt.replace("%E5", "a");
  txt.replace("%E7", "c");
  txt.replace("%E8", "e");
  txt.replace("%E9", "e");
  txt.replace("%EA", "e");
  txt.replace("%EB", "e");
  txt.replace("%EC", "i");
  txt.replace("%ED", "i");
  txt.replace("%EE", "i");
  txt.replace("%EF", "i");
  txt.replace("%F0", "o");
  txt.replace("%F1", "n");
  txt.replace("%F2", "o");
  txt.replace("%F3", "o");
  txt.replace("%F4", "o");
  txt.replace("%F5", "o");
  txt.replace("%F6", "o");
  txt.replace("%F7", "o");
  txt.replace("%F8", "o");
  txt.replace("%F9", "u");
  txt.replace("%FA", "u");
  txt.replace("%FB", "u");
  txt.replace("%FC", "y");
  txt.replace("%FF", "y");
  return txt;
}

// **************************************************
String alpha_removespecial(String txt) {
  txt.replace("à", "a"); // a
  txt.replace("â", "a");
  txt.replace("ä", "a");
  txt.replace("á", "a");
  txt.replace("ã", "a");
  txt.replace("å", "a");
  txt.replace("î", "i"); // i
  txt.replace("ï", "i");
  txt.replace("ì", "i");
  txt.replace("í", "i");
  txt.replace("ô", "o"); // o
  txt.replace("ö", "o");
  txt.replace("ò", "o");
  txt.replace("ó", "o");
  txt.replace("õ", "o");
  txt.replace("ù", "u"); // u
  txt.replace("û", "u");
  txt.replace("ü", "u");
  txt.replace("ú", "u");
  txt.replace("é", "e"); // e
  txt.replace("è", "e");
  txt.replace("ê", "e");
  txt.replace("ë", "e");
  txt.replace("ç", "c"); // others
  txt.replace("ñ", "n");
  txt.replace("ÿ", "y");
  txt.replace("ý", "y");
  return txt;
}