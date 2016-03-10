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
// along with this program. If not, see <http://www.gnu.org/licenses/>.


@import Foundation;
@import CoreGraphics;


@protocol ZMImagePreprocessorHandler;


@interface ZMImagePreprocessor : NSObject

- (instancetype)initWithImageData:(NSData *)imageData processingQueue:(NSOperationQueue *)queue;

@property (nonatomic, readonly) NSData *imageData;
@property (nonatomic, readonly) NSOperationQueue *processingQueue;

- (void)generateRepresentationsWithResultHandler:(id <ZMImagePreprocessorHandler>)handler callbackQueue:(NSOperationQueue *)callbackQueue;

+ (NSOperationQueue *)createSuitableImagePreprocessingQueue;

@end



@interface ZMImagePreprocessor (ImageSize)

+ (CGSize)sizeOfPrerotatedImageAtURL:(NSURL *)fileURL;
+ (CGSize)sizeOfPrerotatedImageWithData:(NSData *)data;
+ (CGSize)imageSizeFromProperties:(NSDictionary *)properties;

@end



@protocol ZMImagePreprocessorHandler <NSObject>

- (void)imagePreprocessor:(ZMImagePreprocessor *)preprocessor didProducePreviewData:(NSData *)imageData;
- (void)imagePreprocessor:(ZMImagePreprocessor *)preprocessor didProduceMediumData:(NSData *)imageData;
- (void)imagePreprocessorDidComplete:(ZMImagePreprocessor *)preprocessor;

@end