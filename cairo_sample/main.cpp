#include <cairo/cairo.h>
#include <FreeImage.h>

int main()
{
    FreeImage_Initialise(true);
    int w = 1024;
    int h = 700;
    FIBITMAP * bitmap = FreeImage_Allocate(w, h, 32, 8, 8, 8);
    BYTE * data = FreeImage_GetBits(bitmap);
    cairo_surface_t * surface = cairo_image_surface_create_for_data(data, CAIRO_FORMAT_ARGB32, w, h, w * 4);
    cairo_t* pCairoContext = cairo_create(surface);
    cairo_surface_destroy(surface);
    if(pCairoContext)
    {
        double  x=100.6,  y=328.0;
        double  x1=102.4 + 100, y1=130.4,
                x2=153.6 + 240, y2=405.6,
                x3=230.4 + 400, y3=200;

        cairo_move_to (pCairoContext, x, y);
        cairo_curve_to (pCairoContext, x1, y1, x2, y2, x3, y3);

        cairo_set_line_width (pCairoContext, 1.0);
        cairo_set_source_rgb(pCairoContext,1.0, 0.0, 0.0);
        cairo_stroke (pCairoContext);
        cairo_destroy(pCairoContext);
    }
    FreeImage_Save(FIF_PNG, bitmap, "my.png", 0);
    return 0;
}
