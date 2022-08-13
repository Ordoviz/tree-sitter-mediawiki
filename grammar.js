module.exports = grammar({
  name: 'mediawiki',
  extras: $ => [], // whitespace is significant
  rules: {
    source_file: $ => repeat($._root),
    
    _root: $ => choice(
      $.wikilink,
      $._plaintext, // let's hope this acts as a fallback if nothing else matches
    ),
    
    wikilink: $ => seq(
      '[[',
      field('target', $.linktarget),
      optional(
        field('anchor', $.linkanchor)
      ),
      /(\|.*?)?\]\]/ // two "]" optionally preceeded by "|linktext"
    ),
    
    linktarget: $ => /[^#|\]]+/, // everything until first "#" or "]" char
    linkanchor: $ => /#[^|\]]+/, // this assumes the anchor contains no "]"

    _plaintext: $ => /.|\n/
  }
});
