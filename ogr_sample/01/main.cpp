#include <ogrsf_frmts.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
int main()
{
    const char * pszDriverName = "ESRI Shapefile";
    OGRSFDriver * pDriver = NULL;
    OGRRegisterAll();

    pDriver = OGRSFDriverRegistrar::GetRegistrar()->GetDriverByName(pszDriverName);
    if (pDriver == NULL)
    {
        std::cout << "OGR Driver not available" << std::endl;
    }
    OGRDataSource * pDataSource = NULL;

    pDataSource = pDriver->CreateDataSource("temp.shp", NULL);
    if (pDataSource == NULL)
    {
        std::cout << " shp DataSource output failed" << std::endl;
    }

    OGRLayer * layer = NULL;
    layer = pDataSource->CreateLayer("point_out_layer", NULL, wkbPoint);

    if (layer == NULL)
    {
        std::cout << "Create Layer Failed" << std::endl;
    }

    OGRFieldDefn nameDef("Name", OFTString);
    nameDef.SetWidth(32);

    layer->CreateField(&nameDef);
    double x = 0.0;
    double y = 0.0;
    char szName[33];
    while (!feof(stdin) && fscanf(stdin, "%lf,%lf,%32s", &x, &y, szName) == 3)
    {
        OGRFeature * feature = NULL;
        feature = OGRFeature::CreateFeature(layer->GetLayerDefn());
        feature->SetField("Name", szName);;

        OGRPoint pt;
        pt.setX(x);
        pt.setY(y);

        feature->SetGeometry(&pt);

        if (layer->CreateFeature(feature) != OGRERR_NONE)
        {

        }
        OGRFeature::DestroyFeature(feature);
    }
    OGRDataSource::DestroyDataSource(pDataSource);
    return 0;
}
