#include <cairo/cairo.h>
#include <FreeImage.h>

int main()
{
    const char * imageFile = "/home/cc/Images/1.jpg";
    FreeImage_Initialise(true);
    FIBITMAP * bitmap = FreeImage_Load(FIF_JPEG, imageFile);
    unsigned int w = FreeImage_GetWidth(bitmap);
    unsigned int h = FreeImage_GetHeight(bitmap);
    FREE_IMAGE_COLOR_CHANNEL type;
            FreeImage_GetChannel(bitmap, type);
    BYTE * data = FreeImage_GetBits(bitmap);

    return 0;
}
