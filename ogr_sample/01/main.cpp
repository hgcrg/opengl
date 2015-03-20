#include <ogrsf_frmts.h>

int main()
{
    const char * pszDriverName = "ESRI Shapefile";
    OGRSFDriver * pDriver = NULL;
    OGRRegisterAll();
    pDriver = OGRSFDriverRegistrar::GetRegistrar()->GetDriverByName(pszDriverName);
    return 0;
}
