/****************************************************************************
 Copyright (c) 2008-2010 Ricardo Quesada
 Copyright (c) 2010-2012 cocos2d-x.org
 Copyright (c) 2011      Zynga Inc.
 Copyright (c) 2013-2014 Chukong Technologies Inc.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef COCOS_2D_CCSpritePolygonCACHE_H__
#define COCOS_2D_CCSpritePolygonCACHE_H__

#include "renderer/CCTrianglesCommand.h"
#include "2d/CCAutoPolygon.h"

NS_CC_BEGIN



typedef std::vector<PolygonInfo*> VecSpritePolygonInfo;
typedef std::unordered_map<std::string, VecSpritePolygonInfo> MapSpritePolygonInfo;

class CC_DLL SpritePolygonCache: public cocos2d::Ref
{
public:
    virtual ~SpritePolygonCache();
    static SpritePolygonCache* getInstance();
    static void destroyInstance();
    PolygonInfo* addSpritePolygonCache(const std::string& filePath, const cocos2d::Rect& rect, const cocos2d::TrianglesCommand::Triangles& triangles);
    PolygonInfo* getSpritePolygonCache(const std::string& filePath, const cocos2d::Rect& rect, float optimization);
    
    void removeSpritePolygonCache(const std::string& filePath, const cocos2d::Rect* rect = nullptr);
    void removeAllSpritePolygonCache();
    void removeUnusedSpritePolygonCache();
    bool isSpritePolygonCacheExist(const std::string& filePath, const cocos2d::Rect& rect);
    
    static void printInfo(PolygonInfo &info);
protected:
    SpritePolygonCache();
    void init();
private:
    static SpritePolygonCache* s_spritePolygonCache;
    MapSpritePolygonInfo _spritePolygonCacheMap;
    
};

NS_CC_END

#endif // #ifndef COCOS_2D_CCSpritePolygonCACHE_H__
