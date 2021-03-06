// 
// Wire
// Copyright (C) 2016 Wire Swiss GmbH
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program. If not, see http://www.gnu.org/licenses/.
// 


@import Foundation;

#import <zimages/ZMImageOwner.h>


@interface ZMAssetMetaDataEncoder : NSObject

+ ( NSDictionary * __nonnull )contentDispositionForImageOwner:(id<ZMImageOwner> __nonnull)imageOwner
                                                       format:(ZMImageFormat)format
                                               conversationID:(NSUUID * __nonnull)convID
                                                correlationID:(NSUUID * __nonnull)correlationID;


+ ( NSDictionary * __nonnull )createAssetDataWithID:(NSUUID * __nonnull)identifier
                                         imageOwner:(id<ZMImageOwner> __nonnull)imageOwner
                                             format:(ZMImageFormat)format
                                      correlationID:(NSUUID * __nonnull)correlationID;


@end

