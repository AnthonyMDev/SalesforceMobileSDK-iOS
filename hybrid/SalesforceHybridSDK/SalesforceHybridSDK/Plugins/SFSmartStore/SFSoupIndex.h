/*
 Copyright (c) 2011, salesforce.com, inc. All rights reserved.
 Author: Todd Stellanova
 
 Redistribution and use of this software in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice, this list of conditions
 and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of
 conditions and the following disclaimer in the documentation and/or other materials provided
 with the distribution.
 * Neither the name of salesforce.com, inc. nor the names of its contributors may be used to
 endorse or promote products derived from this software without specific prior written
 permission of salesforce.com, inc.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>


extern NSString * const kSoupIndexTypeString;
extern NSString * const kSoupIndexTypeDate;


@interface SFSoupIndex : NSObject {
    NSString *_columnType;
}

@property (nonatomic, retain) NSString *path;
@property (nonatomic, strong) NSString *columnType;

@property (nonatomic, retain) NSString *indexType;
@property (nonatomic, retain) NSString *indexedColumnName;
@property (nonatomic, retain) NSString *indexName;


/**
 @param indexSpec the indexSpec to use
 @return initialized index object
 */
- (id)initWithIndexSpec:(NSDictionary*)indexSpec;

/**
 @param sql The sql that was used to create the index in the db
 @see createSqlWithTableName
 @return initialized index object
 */
- (id)initWithSql:(NSString *)sql;

/**
 @return SQL string that can be used to create the index on the provided table
 @param tableName the table on which the index would be created
 */
- (NSString*)createSqlWithTableName:(NSString*)tableName;

+ (NSString*)indexColumnNameForKeyPath:(NSString*)path;
+ (NSString*)soupIndexNameForKeyPath:(NSString*)path;

@end
