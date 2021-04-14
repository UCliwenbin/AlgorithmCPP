//
//  WCCTrieTreeUtil.h
//  CToC++
//
//  Created by mac on 2021/4/14.
//  Copyright © 2021 lwb. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TrieNodeOC : NSObject

@property (nonatomic, copy) NSString *string;  //用来存储插入过的字符串
@property (nonatomic, assign) int path;  //该字符被划过多少次，用以统计以该字符串作为前缀的字符串的个数
@property (nonatomic, assign) int end;  //以该字符结尾的字符串
@property (nonatomic, strong,readonly) NSMutableDictionary<NSString *,TrieNodeOC *> *dict;  //维护的子树字典（key：为字符，val：节点)


@end

NS_ASSUME_NONNULL_BEGIN

/// OC版本的Tri树的实现
@interface WCCTrieTreeUtil : NSObject
    //插入字符串str
- (void)insert:(NSString *)str;
    //查询字符串str是否出现过，并返回作为前缀几次
- (int)search:(NSString *)str;
    //删除字符串str
- (void)deleteStr:(NSString *)str;
    //打印树中的所有字符串
- (NSArray *)printAll;
    //打印以str作为前缀的单词
- (NSArray *)printPre:(NSString *)str;
    //返回以str为前缀的单词的个数
- (int)prefixNumbers:(NSString *)str;


@end

NS_ASSUME_NONNULL_END
