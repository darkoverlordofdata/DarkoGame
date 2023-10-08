#import <Foundation/Foundation.h>
#import <SDL2/SDL.h>
#import "../tglm.h"
#import "../OpenGL.h"
#import "DGKTexture2D.h"
#import "DGKShader.h"

@interface DGKSpriteRenderer : NSObject  
{
    DGKShader *mShader; 
    GLuint mQuadVAO;
}

- (instancetype)initWithShader:(DGKShader*)shader;
- (void)InitRenderData;
- (NSString*)ToString;
- (void)DrawSprite:(DGKTexture2D*)texture 
Bounds:(SDL_Rect*)bounds
Rotate:(GLfloat)rotate 
Color:(Vec3)color;

@end