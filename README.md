unifont <a href="https://travis-ci.org/r-lyeh/unifont"><img src="https://api.travis-ci.org/r-lyeh/unifont.svg?branch=master" align="right" /></a>
=======

- Unifont is a compact and embeddable terminal 1-bpp font library (C++11).
- Unifont is handy. It supports most european/greek/cyrillic unicode codepoints.
- Unifont is tiny (~400 LOC), header-only, portable and cross-platform.
- Unifont is aimed to gamedev and debugging sessions.
- Unifont is zlib/libpng licensed.

## api
- Instance an `unifont(color *framebuffer, unsigned width, color (*make_rgba)(r,g,b,a))` class.
- While using an unifont class, the external framebuffer must point to a valid memory address.
- Then use following methods as desired:
```c++
render_string(x,y,style,const char* utf8);
render_string(x,y,style,const char* utf8, const color &c);
render_string(x,y,style,const char* utf8, const color* gradient8x8);
render_string(x,y,style,const vector<int> &codepoints);
render_string(x,y,style,const vector<int> &codepoints, const color &c);
render_string(x,y,style,const vector<int> &codepoints, const color* gradient8x8);
```
- Style is an `enum { NORMAL, INVERT, SHADOW, RETRO }` flag mask.
- All methods return an `struct { unsigned w, h; }` dimensions rectangle.
- For a more detailed sample check [sample.cc file](sample.cc).

## preview
![image](https://raw.github.com/r-lyeh/depot/master/unifont.png)

## notes
- To replace embedded built-in font see [ttf2mono.cc source code](redist/ttf2mono.cc)
- Sample requires [libspot](https://github.com/r-lyeh/spot) to compile. 

## licenses
- [Unifont](https://github.com/r-lyeh/unifont), zlib/libpng licensed.
- [PressStart2P.ttf v2.14](http://www.zone38.net/font/) by Cody "CodeMan38" Boisclair (SIL Open Font License).
- [UTF-8 dfa decoder](http://bjoern.hoehrmann.de/utf-8/decoder/dfa/) by Bjoern Hoehrmann (MIT license).
- Gradient retro style mask taken from [DoDonPachi arcade](http://en.wikipedia.org/wiki/DoDonPachi).

## changelog
- v1.0.0 (2015/05/05)
  - initial revision
