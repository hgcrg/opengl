#include <GL/gl.h>
#include <osgViewer/Viewer>
#include <FreeImage.h>
class MyGeode : public osg::Geode
{
    class MyDrawable : public osg::Drawable
    {
        META_Object(osg, MyDrawable)
        public:
            MyDrawable()
        {
            Init();
        }

        MyDrawable(MyGeode * geode)
            :_geode(NULL)
        {
            _geode = geode;
            Init();
        }
        ~MyDrawable()
        {

        }
        void Init()
        {
            _first = true;
            setUseVertexBufferObjects(true);
            setUseDisplayList(false);
            setDataVariance(osg::Object::DYNAMIC);
        }

        MyDrawable(const osg::Drawable & drawable, const osg::CopyOp & copyop)
        {

        }

        virtual void drawImplementation(osg::RenderInfo &renderInfo) const
        {
            if (_first)
            {
                _first = false;
                _geode->Init();
            }
            if (_geode)
            {
                _geode->Draw();
            }
        }
    private:
        MyGeode * _geode;
        mutable bool _first;
    };
public:
    MyGeode()
    {
        addDrawable(new MyDrawable(this));
    }

    ~MyGeode()
    {

    }
    void Init()
    {
        FreeImage_Initialise(true);
        FIBITMAP * bitmap = FreeImage_Load(FIF_JPEG, "/home/cc/Images/1.jpg");
        int w = FreeImage_GetWidth(bitmap);
        int h = FreeImage_GetHeight(bitmap);
        BYTE * data = FreeImage_GetBits(bitmap);
        glGenTextures(1, &m_Tex);
        glBindTexture(GL_TEXTURE_2D, m_Tex);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, w, h, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glEnable(GL_TEXTURE_2D);
    }

    void Draw()
    {

        glBindTexture(GL_TEXTURE_2D, m_Tex);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f); // 纹理和四边形的左下
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f); // 纹理和四边形的右下
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f); // 纹理和四边形的右上
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f); // 纹理和四边形的左上
        glEnd();
    }
    GLuint m_Tex;
};
int main()
{
    osgViewer::Viewer viewer;
    osg::Group * root = new osg::Group;
    root->addChild(new MyGeode);
    viewer.setSceneData(root);
    viewer.setUpViewInWindow(35, 35, 800, 600);
    viewer.getCamera()->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
    return viewer.run();
}
