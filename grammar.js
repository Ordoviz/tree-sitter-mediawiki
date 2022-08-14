const HTML = require('tree-sitter-html/grammar');

module.exports = grammar(HTML, {
  name: 'mediawiki',

  rules: {
    _node: $ => choice(
      $._inlinemarkup,
      $._blockmarkup
    ),
    
    _inlinemarkup: $ => choice(
      $.extlink,
      $.wikilink,
      $.template,
      $.parameter,
      $.element,
      $.erroneous_end_tag,
      /.|\n/ // plain text
    ),
    
    _blockmarkup: $ => choice(
      $.heading,
    ),

    extlink: $ => seq(
      '[',
      field('target', $.url),
      optional(seq(
        ' ',
        optional(field('label', $.extlinklabel))
      )),
      ']'
    ),

    wikilink: $ => seq(
      '[[',
      field('target', $.linktarget),
      optional(
        field('anchor', $.linkanchor)
      ),
      optional(seq(
        '|',
        optional(field('label', $.linklabel))
      )),
      ']]'
    ),

    template: $ => seq(
      '{{',
      field('name', $.templatename),
      repeat(seq('|', $.templateparam)),
      '}}'
    ),

    // parameter in a template, e.g. {{{name|default}}}
    parameter: $ => seq(
      '{{{',
      field('name', $.paramname),
      optional(seq('|', optional($._paramdefault))),
      '}}}'
    ),
    
    heading: $ => choice( $.h1, $.h2, $.h3, $.h4, $.h5, $.h6 ),
    h1: $ => seq('\n=',      /[^=\n]+/, '='),
    h2: $ => seq('\n==',     /[^=\n]+/, '=='),
    h3: $ => seq('\n===',    /[^=\n]+/, '==='),
    h4: $ => seq('\n====',   /[^=\n]+/, '===='),
    h5: $ => seq('\n=====',  /[^=\n]+/, '====='),
    h6: $ => seq('\n======', /[^=\n]+/, '======'),
    
    url: $ => seq(
      /([a-zA-Z0-9.-]+:|\/\/)/, // URI scheme or protocol relative
      /[^\s\]]+/                // all except whitespace and "]"
    ),
    extlinklabel: $ => /[^\s\]]+/, // all except whitespace and "]"

    linktarget: $ => /[^#|\]]+/, // everything until first "#", "|", or "]" char
    linkanchor: $ => /#[^|\]]+/, // this assumes the anchor contains no "]"
    linklabel:  $ => repeat1(/[^\]]|\][^\]]/),
    
    templatename: $ => /[^|}]+/, // everything until first "|" or "}" char
    templateparam: $ => seq(
      optional(field('key', $.templatekey)),
      field('value', $.templatevalue)
    ),
    templatekey: $ => /[^|}]+?=/,
    templatevalue: $ => repeat1($._node),

    paramname: $ => /[^|}]+/, // everything until first "|" or "}" char
    _paramdefault: $ => field('value', repeat1($._node))
  }
});
