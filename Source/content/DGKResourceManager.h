#import <Foundation/Foundation.h>
#import <SDL2/SDL.h>
#import <SDL2/SDL_image.h>
#import "../OpenGL.h"
#import "../graphics/DGKTexture2D.h"
#import "../graphics/DGKShader.h"


@interface DGKResourceManager : NSObject
@property (nonatomic, retain) NSMutableDictionary* Shaders;
@property (nonatomic, retain) NSMutableDictionary* Textures;

+ (DGKShader*)LoadShader:(NSString*)name Vertex:(NSString*) vertex Fragment:(NSString *)fragment;
+ (DGKShader*)GetShader:(NSString*)name;
+ (DGKTexture2D*)LoadTexture:(NSString*)name Path:(NSString*)path Alpha:(GLboolean)alpha;
+ (DGKTexture2D*)GetTexture:(NSString*)name;
+ (void)Clear;

+ (DGKShader*)LoadShaderFromFile:(NSString*) vertex Fragment:(NSString*) fragment;
+ (DGKTexture2D*)LoadTextureFromFile:(NSString*)path Alpha:(GLboolean)alpha;
+ (NSString*)ResourcePath:(NSString*)filename;
@end