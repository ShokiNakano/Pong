#pragma once

#include"graphic.h"
#include"NAME.h"
#include"COLOR.h"
//struct ID3D11Buffer;
//class SHADER;
class FILE_BUFFER;
//class VECTOR2;
//class VECTOR;
//class MATRIX;

class TEXTURE{
public:
    //static void createVertex();
    //static void destroyVertex();
    //TEXTURE(){}
    TEXTURE( FILE_BUFFER& fb );
    //TEXTURE( const char* fileName );
    //TEXTURE( TEXTURE_OBJ* obj, int width, int height );
    ~TEXTURE();
    //void create( const char* filename );
    //２Ｄ描画：posに画像左上がくる
    //void draw( SHADER* shader, const VECTOR2& pos, const COLOR& color=COLOR(1,1,1,1) );
    //void draw( SHADER* shader, const float x, float y, const COLOR& color=COLOR(1,1,1,1) );
    //２Ｄ描画：posに画像中央がくる。回転もできる。
    //void draw( SHADER* shader, const VECTOR2& pos, float radian, const COLOR& color=COLOR(1,1,1,1) );
    //void draw( SHADER* shader, const float x, float y, float radian, const COLOR& color=COLOR(1,1,1,1) );//posに画像中央がくる。回転もできる。
    //３Ｄ描画
    //void draw( SHADER* shader, const MATRIX& world, const COLOR& color=COLOR(1,1,1,1) );
    TEXTURE_OBJ** obj();
    int w(){ return W; }
    int h(){ return H; }
    const NAME& name() const;
private:
    //static ID3D11Buffer* VertexObj;
    TEXTURE_OBJ* Obj=0;
    int W=0;
    int H=0;
    NAME Name;
};
