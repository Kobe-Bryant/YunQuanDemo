//
//  SnailMessageInputView.h
//  VoiceRecorderDemo
//
//  Created by LazySnail on 14-6-21.
//  Copyright (c) 2014年 yunlai. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SnailMessageTextView.h"

typedef NS_ENUM(NSInteger, SnailMessageInputViewStyle) {
    // 分两种,一种是iOS6样式的，一种是iOS7样式的
    SnailMessageInputViewStyleQuasiphysical,
    SnailMessageInputViewStyleFlat
};

@protocol SnailMessageInputViewDelegate <NSObject>

@required

/**
 *  输入框刚好开始编辑
 *
 *  @param messageInputTextView 输入框对象
 */
- (void)inputTextViewDidBeginEditing:(SnailMessageTextView *)messageInputTextView;

/**
 *  输入框将要开始编辑
 *
 *  @param messageInputTextView 输入框对象
 */
- (void)inputTextViewWillBeginEditing:(SnailMessageTextView *)messageInputTextView;

@optional

/**
 *  在发送文本和语音之间发送改变时，会触发这个回调函数
 *
 *  @param changed 是否改为发送语音状态
 */
- (void)didChangeSendVoiceAction:(BOOL)changed;

/**
 *  发送文本消息，包括系统的表情
 *
 *  @param text 目标文本消息
 */
- (void)didSendTextAction:(NSString *)text;

/**
 *  按下录音按钮开始录音
 */
- (void)didStartRecordingVoiceAction;
/**
 *  手指向上滑动取消录音
 */
- (void)didCancelRecordingVoiceAction;
/**
 *  松开手指完成录音
 */
- (void)didFinishRecoingVoiceAction;
/**
 *  当手指离开按钮的范围内时，主要为了通知外部的HUD
 */
- (void)didDragOutsideAction;
/**
 *  当手指再次进入按钮的范围内时，主要也是为了通知外部的HUD
 */
- (void)didDragInsideAction;

/**
 *  发送第三方表情
 *
 *  @param facePath 目标表情的本地路径
 */
- (void)didSendFaceAction:(BOOL)sendFace;

/**
 *  点击+号按钮Action
 */
- (void)didSelectedMultipleMediaAction:(BOOL)openMutipleMedia;

@end

@interface SnailMessageInputView : UIImageView

@property (nonatomic, weak) id <SnailMessageInputViewDelegate> delegate;

/**
 *  用于输入文本消息的输入框
 */
@property (nonatomic, weak, readonly) SnailMessageTextView *inputTextView;


/**
 *  当前输入工具条的样式
 */
@property (nonatomic, assign) SnailMessageInputViewStyle messageInputViewStyle;

/**
 *  是否允许发送语音
 */
@property (nonatomic, assign) BOOL allowsSendVoice; // default is YES

/**
 *  是否允许发送多媒体
 */
@property (nonatomic, assign) BOOL allowsSendMultiMedia; // default is YES

/**
 *  是否支持发送表情
 */
@property (nonatomic, assign) BOOL allowsSendFace; // default is YES

/**
 *  切换文本和语音的按钮
 */
//@property (nonatomic, weak, readonly) UIButton *voiceChangeButton;

/**
 *  +号按钮
 */
@property (nonatomic, weak, readonly) UIButton *multiMediaSendButton;

/**
 *  第三方表情按钮
 */
@property (nonatomic, weak, readonly) UIButton *faceSendButton;

/**
 *  语音录制按钮
 */
@property (nonatomic, weak, readonly) UIButton *holdDownButton;

#pragma mark - Message input view

/**
 *  动态改变高度
 *
 *  @param changeInHeight 目标变化的高度
 */
- (void)adjustTextViewHeightBy:(CGFloat)changeInHeight;

/**
 *  获取输入框内容字体行高
 *
 *  @return 返回行高
 */
+ (CGFloat)textViewLineHeight;

/**
 *  获取最大行数
 *
 *  @return 返回最大行数
 */
+ (CGFloat)maxLines;

/**
 *  获取根据最大行数和每行高度计算出来的最大显示高度
 *
 *  @return 返回最大显示高度
 */
+ (CGFloat)maxHeight;

/**
 *  重置所有的聊天按钮
 */
- (void)resetAllButton;

/**
 *  判断按钮是否已展开聊天输入界面
 */
- (BOOL)isInputSomething;

@end
