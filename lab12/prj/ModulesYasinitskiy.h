#ifndef MODULESYASINITSKIY_H_INCLUDED
#define MODULESYASINITSKIY_H_INCLUDED

class ClassLab12_Yasinitskiy {
    private:
        float height;
        float radius;
    public:
        ClassLab12_Yasinitskiy(float, float);
        float getHeight();
        float getRadius();
        float getVolume();
        bool setHeight(float);
        bool setRadius(float);
};

#endif // MODULESYASINITSKIY_H_INCLUDED
