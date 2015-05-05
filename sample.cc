// sample requires libspot (https://github.com/r-lyeh/spot)
// file must be saved with utf-8 encoding
// r-lyeh, public domain

#include "unifont.hpp"

#if !defined(USE_LIBSPOT)

int main() {

}

#else

#include "spot/spot.hpp"
#include "spot/samples/cimg.hpp"

spot::pixel make_rgba( uint8_t r, uint8_t g, uint8_t b, uint8_t a ) {
    return spot::rgba(r,g,b,a);
}

int main() {
    spot::texture img(600, 600);
    for( unsigned y = 0; y < 600; ++y ) {
        for( unsigned x = 0; x < 600; ++x ) {
            img.at( x, y ) = spot::hsla( ( (x+y) % 255 ) / 255.0, (x+y) / 600.0, (x+y) / 1200.0, 1 );
        }
    }

    unifont<spot::pixel> font( &img[0], img.w, &make_rgba );

    // styles
    int normal = font.NORMAL;
    int invert = font.INVERT;
    int shadow = font.SHADOW;
    int retro  = font.RETRO;

    // coord
    int ox = 10, oy = 10;

    oy += font.render_string( ox, oy, 0|2, "ee: õueaiaäär" ).h;
    oy += font.render_string( ox, oy, 0|2, "es: ¡¿Cómo que por qué se escribe cigüeña?!" ).h;
    oy += font.render_string( ox, oy, 0|2, "fi: Vesihiisi sihisi hississä." ).h;
    oy += font.render_string( ox, oy, 0|2, "fr: D'où êtes-vous ? Ça va? Allô? Pouvez-vous répéter, s'il vous plaît?" ).h;
    oy += font.render_string( ox, oy, 0|2, "ge: ბაყაყი წყალში ყიყინებს (unsupported)" ).h;
    oy += font.render_string( ox, oy, 0|2, "gr: Χάρηκα για την γνωρημία. Η αθασιά της Αϊσές αν έχει αθάσια, ας έχει" ).h;
    oy += font.render_string( ox, oy, 0|2, "hr: Cvrči cvrči cvrčak na čvoru crne smrče" ).h;
    oy += font.render_string( ox, oy, 0|2, "is: Ég get etið gler án þess að meiða mig" ).h;
    oy += font.render_string( ox, oy, 0|2, "pl: Słucham. Dzięki. Skąd jesteś?" ).h;
    oy += font.render_string( ox, oy, 0|2, "ro: Mulţumesc! Însănătoșire grabnică! Îți doresc." ).h;
    oy += font.render_string( ox, oy, 0|2, "ru: Будем здоровы!" ).h;
    oy += font.render_string( ox, oy, 0|2, "**: (unsupported) أَلَمٌ أَلَمَّ أَلَمْ أُلِمَّ بِدَائِهِ ... إِنْ آنَ آنٌ آنَ آنُ أَوَانِهِ" ).h;

    oy += font.render_string( ox, oy, 0, "+-------------------------------------+" ).h;
    oy += font.render_string( ox, oy, 0, "| HELLO WORLD!! $01234567.89# abc ABC |X" ).h;
    oy += font.render_string( ox, oy, 0, "+-------------------------------------+X" ).h;
    oy += font.render_string( ox, oy, 0, " XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" ).h;

    oy += font.render_string( ox, oy, 0,        "yellow: color test without shadow", make_rgba(255,255,0,255) ).h;
    oy += font.render_string( ox, oy, 0|shadow, "cherry: color test with shadow", make_rgba(222,49,99,255) ).h;

    oy += font.render_string( ox, oy, normal,       "style: plain" ).h;
    oy += font.render_string( ox, oy, invert,       "style: invert" ).h;
    oy += font.render_string( ox, oy, shadow,       "style: shadow" ).h;
    oy += font.render_string( ox, oy, retro,        "style: retro" ).h;
    oy += font.render_string( ox, oy, retro|shadow, "style: retro+shadow" ).h;
    auto A = make_rgba(255,255,255,255), B = make_rgba(0,255,255,255), C = make_rgba(0,128,255,255), D = make_rgba(40,80,255,255);
    decltype(A) gradient[] = {
        A,A,A,A,A,A,A,A,
        A,A,A,A,A,A,A,A,
        B,B,B,B,B,B,B,B,
        B,B,B,B,B,B,B,B,
        C,C,C,C,C,C,C,C,
        C,C,C,C,C,C,C,C,
        D,D,D,D,D,D,D,D,
        D,D,D,D,D,D,D,D,
    };
    oy += font.render_string( ox, oy, shadow, "style: custom gradient fill", gradient ).h;

    oy += font.render_glyphs( ox, oy, shadow ).h;

    img.copy( 0, 0, 380, 520 ).save_as_png("unifont.png");
    display( img, "mono fonts preview" );
}

#endif

