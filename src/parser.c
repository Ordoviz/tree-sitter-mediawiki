#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 10
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 10
#define ALIAS_COUNT 0
#define TOKEN_COUNT 6
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 3

enum {
  anon_sym_LBRACK_LBRACK = 1,
  aux_sym_wikilink_token1 = 2,
  sym_linktarget = 3,
  sym_linkanchor = 4,
  sym__plaintext = 5,
  sym_source_file = 6,
  sym__root = 7,
  sym_wikilink = 8,
  aux_sym_source_file_repeat1 = 9,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LBRACK_LBRACK] = "[[",
  [aux_sym_wikilink_token1] = "wikilink_token1",
  [sym_linktarget] = "linktarget",
  [sym_linkanchor] = "linkanchor",
  [sym__plaintext] = "_plaintext",
  [sym_source_file] = "source_file",
  [sym__root] = "_root",
  [sym_wikilink] = "wikilink",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LBRACK_LBRACK] = anon_sym_LBRACK_LBRACK,
  [aux_sym_wikilink_token1] = aux_sym_wikilink_token1,
  [sym_linktarget] = sym_linktarget,
  [sym_linkanchor] = sym_linkanchor,
  [sym__plaintext] = sym__plaintext,
  [sym_source_file] = sym_source_file,
  [sym__root] = sym__root,
  [sym_wikilink] = sym_wikilink,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LBRACK_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_wikilink_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_linktarget] = {
    .visible = true,
    .named = true,
  },
  [sym_linkanchor] = {
    .visible = true,
    .named = true,
  },
  [sym__plaintext] = {
    .visible = false,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__root] = {
    .visible = false,
    .named = true,
  },
  [sym_wikilink] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_anchor = 1,
  field_target = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_anchor] = "anchor",
  [field_target] = "target",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_target, 1},
  [1] =
    {field_anchor, 2},
    {field_target, 1},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '[') ADVANCE(12);
      if (lookahead == '[') ADVANCE(13);
      END_STATE();
    case 1:
      if (lookahead == '#') ADVANCE(5);
      if (lookahead == ']') ADVANCE(2);
      if (lookahead == '|') ADVANCE(4);
      if (lookahead != 0) ADVANCE(10);
      END_STATE();
    case 2:
      if (lookahead == ']') ADVANCE(8);
      END_STATE();
    case 3:
      if (lookahead == ']') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(4);
      END_STATE();
    case 4:
      if (lookahead == ']') ADVANCE(3);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead != 0 &&
          lookahead != ']' &&
          lookahead != '|') ADVANCE(11);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_LBRACK_LBRACK);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(aux_sym_wikilink_token1);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(aux_sym_wikilink_token1);
      if (lookahead == ']') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(4);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_linktarget);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != ']' &&
          lookahead != '|') ADVANCE(10);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_linkanchor);
      if (lookahead != 0 &&
          lookahead != ']' &&
          lookahead != '|') ADVANCE(11);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym__plaintext);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym__plaintext);
      if (lookahead == '[') ADVANCE(7);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 1},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(1),
    [sym__plaintext] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(8),
    [sym__root] = STATE(2),
    [sym_wikilink] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(5),
    [sym__plaintext] = ACTIONS(7),
  },
  [2] = {
    [sym__root] = STATE(3),
    [sym_wikilink] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(9),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(5),
    [sym__plaintext] = ACTIONS(11),
  },
  [3] = {
    [sym__root] = STATE(3),
    [sym_wikilink] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(13),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(15),
    [sym__plaintext] = ACTIONS(18),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(23), 1,
      sym__plaintext,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK_LBRACK,
  [8] = 2,
    ACTIONS(27), 1,
      sym__plaintext,
    ACTIONS(25), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK_LBRACK,
  [16] = 2,
    ACTIONS(29), 1,
      aux_sym_wikilink_token1,
    ACTIONS(31), 1,
      sym_linkanchor,
  [23] = 1,
    ACTIONS(33), 1,
      sym_linktarget,
  [27] = 1,
    ACTIONS(35), 1,
      ts_builtin_sym_end,
  [31] = 1,
    ACTIONS(37), 1,
      aux_sym_wikilink_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 8,
  [SMALL_STATE(6)] = 16,
  [SMALL_STATE(7)] = 23,
  [SMALL_STATE(8)] = 27,
  [SMALL_STATE(9)] = 31,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(7),
  [18] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_wikilink, 3, .production_id = 1),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_wikilink, 3, .production_id = 1),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_wikilink, 4, .production_id = 2),
  [27] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_wikilink, 4, .production_id = 2),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [35] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_mediawiki(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
