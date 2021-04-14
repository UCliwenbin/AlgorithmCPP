//
//  WCCTrieTreeUtil.m
//  CToC++
//
//  Created by mac on 2021/4/14.
//  Copyright © 2021 lwb. All rights reserved.
//

#import "WCCTrieTreeUtil.h"

@interface TrieNodeOC ()

@property (nonatomic, strong, readwrite) NSMutableDictionary *dict;

@end

@implementation TrieNodeOC

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.dict = [NSMutableDictionary dictionary];
        self.path = 0;
        self.end = 0;
        self.string = @"";
    }
    return self;
}

@end


@interface WCCTrieTreeUtil()

@property (nonatomic, strong) TrieNodeOC *root;

@end

#define subStr(OrigStr,location) \
    [OrigStr substringWithRange:NSMakeRange(location, 1)]

@implementation WCCTrieTreeUtil

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.root = [[TrieNodeOC alloc] init];
    }
    return self;
}

//插入字符串str
- (void)insert:(NSString *)str {
    if (str == nil || str.length == 0) {
        return;
    }
    TrieNodeOC *curNode = self.root;
    for (int i = 0; i < str.length; i++) {
        NSString *strA = subStr(str, i);
        if (curNode.dict[strA] == nil) {
            curNode.dict[strA] = [[TrieNodeOC alloc] init];
        }
        curNode = curNode.dict[strA];
        curNode.path++;
    }
    curNode.end++;
    curNode.string = str;
    
}
//查询字符串str是否出现过，并返回作为前缀几次
- (int)search:(NSString *)str {
    if (str == nil || str.length == 0) {
        return 0;
    }
    TrieNodeOC *curNode = self.root;
    for (int i = 0; i < str.length; i++) {
        NSString *tempStr = subStr(str, i);
        if (curNode.dict[tempStr] == nil) {
            return 0;
        }
        curNode = curNode.dict[tempStr];
    }
    return curNode.end;
}
//删除字符串str
- (void)deleteStr:(NSString *)str {
    if (str == nil || str.length == 0) {
        return;
    }
    //如果字符串存在，那么可以删除，否则直接返回
    if ([self search:str] == 0) return;
    TrieNodeOC *curNode = self.root;
    for (int i = 0; i < str.length; i++) {
        NSString *tempStr = subStr(str, i);
        if (--curNode.dict[tempStr].path == 0) {
            [curNode.dict removeObjectForKey:tempStr];
            break;
        }
        curNode = curNode.dict[tempStr];
    }
    curNode.end--;
}

- (void)_printAll:(TrieNodeOC *)node ArrayRes:(NSMutableArray *)array {
    NSArray *keys = node.dict.allKeys;
    for (int i = 0; i < keys.count; i++) {
        TrieNodeOC *tempNode = node.dict[keys[i]];
        if (tempNode.string.length > 0) {
            [array addObject:tempNode.string];
        }
        [self _printAll:tempNode ArrayRes:array];
    }
}

- (NSArray *)_printAll:(TrieNodeOC *)node {
    NSMutableArray *result = [NSMutableArray arrayWithCapacity:4];
    [self _printAll:node ArrayRes:result];
    return [result copy];
}

- (NSArray *)printAll {
    return [self _printAll:self.root];
}
//打印以str作为前缀的单词
- (NSArray *)printPre:(NSString *)str {
    if (str == nil || str.length == 0) {
        return nil;
    }
    TrieNodeOC *node = self.root;
    for (int i = 0; i < str.length; i++) {
        NSString *tempStr = subStr(str, i);
        if (node.dict[tempStr] == nil) return nil;
        node = node.dict[tempStr];
    }
    return [self _printAll:node];
}
//返回以str为前缀的单词的个数
- (int)prefixNumbers:(NSString *)str {
    if (str == nil || str.length == 0) {
        return 0;
    }
    TrieNodeOC *node = self.root;
    for (int i = 0; i < str.length; i++) {
        NSString *tempStr = subStr(str, i);
        if (node.dict[tempStr] == nil) return 0;
        node = node.dict[tempStr];
    }
    return node.path;
}

@end
