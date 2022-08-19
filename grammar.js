module.exports = grammar({
  name: 'mediawiki',

  extras: $ => [ $.comment ],

  rules: {
    source_file: $ => repeat($._node),

    _node: $ => choice(
      $._inlinemarkup,
      $._blockmarkup
    ),
    
    _inlinemarkup: $ => choice(
      $.extlink,
      $.wikilink,
      $.template,
      $.parameter,
      $.htmltag,
      $.htmlentity,
      /./
    ),
    
    _blockmarkup: $ => choice(
      $.heading,
      /.|\n/
    ),
    
    htmltag: $ => seq(
      '<',
      optional('/'),
      field('name', $.tagname),
      repeat($._node),
      '>'
    ),

    htmlentity: $ => /&(#[0-9]{1,4}|#x[0-9a-fA-F]{1,4}|[a-zA-Z]+);/,

    comment: $ => seq( '<!--', repeat(/.|\n/), '-->' ),

    extlink: $ => seq(
      '[',
      field('target', $.url),
      optional(seq(
        ' ',
        optional(field('label', $.linklabel))
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
      optional(seq(':', repeat1($._node))),  // argument for parser functions
      repeat(seq('|', optional($.templateparam))),
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
    
    tagname: $ => /[a-zA-Z][\w-]*/,

    url: $ => seq(
      /([a-zA-Z0-9.-]+:|\/\/)/, // URI scheme or protocol relative
      repeat1($._inlinemarkup)
    ),

    linktarget: $ => repeat1($._inlinemarkup),
    linkanchor: $ => seq('#', repeat1($._inlinemarkup)),
    linklabel:  $ => repeat1($._inlinemarkup),
    
    templatename: $ => /[\s:]*[^|\n:<}]+/,
    templateparam: $ => choice(
      field('key', $.templatekey),     // just |key=
      field('value', $.templatevalue), // just |value
      seq(field('key', $.templatekey), field('value', $.templatevalue)), // both
    ),
    templatekey: $ => /[^|}]+?=/,
    templatevalue: $ => repeat1($._node),

    paramname: $ => /[^|}]+/, // everything until first "|" or "}" char
    _paramdefault: $ => field('value', repeat1($._node))
  }
});
