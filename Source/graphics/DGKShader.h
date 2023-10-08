#import <Foundation/Foundation.h>
#import <SDL2/SDL.h>
#import "../tglm.h"
#import "../OpenGL.h"

@interface DGKShader : NSObject  
{
    GLuint mId; 
}
@property (nonatomic, assign) GLuint Id;

- (instancetype)init;
- (NSString*)ToString;
- (DGKShader*)Use;
- (void)CheckCompileErrors:(GLuint)object Type:(NSString*)type;
- (void)Compile:(const char*) vertexSource Fragment:(const char*) fragmentSource;
- (DGKShader*)SetInteger:(const char*)name  Value:(GLint)value;
- (DGKShader*)SetInteger:(const char*)name  Value:(GLint)value  UseShader:(GLboolean) useShader;
- (DGKShader*)SetFloat:(const char*)name  Value:(GLfloat)value;
- (DGKShader*)SetFloat:(const char*)name  Value:(GLfloat)value  UseShader:(GLboolean) useShader;
- (DGKShader*)SetVector2:(const char*)name  Value:(Vec2)value;
- (DGKShader*)SetVector2:(const char*)name  Value:(Vec2)value  UseShader:(GLboolean) useShader;
- (DGKShader*)SetVector3:(const char*)name  Value:(Vec3)value;
- (DGKShader*)SetVector3:(const char*)name  Value:(Vec3)value  UseShader:(GLboolean) useShader;
- (DGKShader*)SetMatrix4:(const char*)name  Value:(Mat)value;
- (DGKShader*)SetMatrix4:(const char*)name  Value:(Mat)value  UseShader:(GLboolean) useShader;

@end