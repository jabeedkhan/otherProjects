//
//  DLPieChart.h
//  DLPieChart
//
//  Created by Dilip Lilaramani on 5/29/13.
//  Copyright (c) 2013 Dilip Lilaramani. All rights reserved.
//

#import <UIKit/UIKit.h>

@class DLPieChart;
@protocol DLPieChartDataSource <NSObject>
@required
- (NSUInteger)numberOfSlicesInPieChart:(DLPieChart *)pieChart;
- (CGFloat)pieChart:(DLPieChart *)pieChart valueForSliceAtIndex:(NSUInteger)index;
@optional
- (UIColor *)pieChart:(DLPieChart *)pieChart colorForSliceAtIndex:(NSUInteger)index;
- (NSString *)pieChart:(DLPieChart *)pieChart textForSliceAtIndex:(NSUInteger)index;
@end

@protocol DLPieChartDelegate <NSObject>
@optional
- (void)pieChart:(DLPieChart *)pieChart willSelectSliceAtIndex:(NSUInteger)index;
- (void)pieChart:(DLPieChart *)pieChart didSelectSliceAtIndex:(NSUInteger)index;
- (void)pieChart:(DLPieChart *)pieChart willDeselectSliceAtIndex:(NSUInteger)index;
- (void)pieChart:(DLPieChart *)pieChart didDeselectSliceAtIndex:(NSUInteger)index;
@end

@protocol CustomDelegate <NSObject>
@optional
- (void)pieChart:(DLPieChart *)pieChart willSelectSliceAtIndex:(NSUInteger)index andWithTheLayer:(CGPoint)point andDisplayVlaue:(NSString*)displayValue andPercentage:(NSString*)percentage;
- (void)pieChart:(DLPieChart *)pieChart willDeselectSliceAtIndex:(NSUInteger)index;
- (void)showPopOverForTheSliceClicked:(CAShapeLayer*)layer;
- (void)removeView;

@end


@interface DLPieChart : UIView <DLPieChartDelegate, DLPieChartDataSource>

@property(nonatomic, strong) id<DLPieChartDataSource> dataSource;
@property(nonatomic, strong) id<CustomDelegate> customDelegate;
@property(nonatomic, strong) id<DLPieChartDelegate> delegate;
@property(nonatomic, assign) CGFloat startPieAngle;
@property(nonatomic, assign) CGFloat animationSpeed;
@property(nonatomic, assign) CGPoint pieCenter;
@property(nonatomic, assign) CGPoint selectedPoint;
@property(nonatomic, assign) CGFloat pieRadius;
@property(nonatomic, assign) BOOL    showLabel;
@property(nonatomic, strong) UIFont  *labelFont;
@property(nonatomic, strong) UIColor *labelColor;
@property(nonatomic, strong) UIColor *labelShadowColor;
@property(nonatomic, assign) CGFloat labelRadius;
@property(nonatomic, assign) CGFloat selectedSliceStroke;
@property(nonatomic, assign) CGFloat selectedSliceOffsetRadius;
@property(nonatomic, assign) BOOL    showPercentage;
@property (nonatomic, assign) NSInteger selectedSliceIndex;

- (id)initWithFrame:(CGRect)frame Center:(CGPoint)center Radius:(CGFloat)radius;
- (void)reloadData;
- (void)setPieBackgroundColor:(UIColor *)color;

- (void)setSliceSelectedAtIndex:(NSInteger)index;
- (void)setSliceDeselectedAtIndex:(NSInteger)index;
- (void)setPieCenter;
- (void)notifyDelegateOfSelectionChangeFrom:(NSUInteger)previousSelection to:(NSUInteger)newSelection withChange:(BOOL)isValueChanged;




//My methods
- (void)renderInLayer:(DLPieChart *)layerHostingView dataArray:(NSMutableArray*)dataArray
           WithColors:(NSMutableArray*)colorsArray andWithDisplayValues:(NSMutableArray*)displayValues;

- (void)customamizeDraw:(DLPieChart*)pieChart
              pieCentre:(CGPoint)pieCentre
            animationSpeed:(CGFloat)speed
            labelRadius:(CGFloat)labelRadius;

-(void)drawLegends:(DLPieChart *)layerHostingView dataArray:(NSMutableArray*)dataArray;

@property (nonatomic ,retain) NSMutableArray *DLDataArray;
@property (nonatomic, retain) NSMutableArray *DLColorsArray;
@property (nonatomic, retain) NSMutableArray *DLDisplayValuesArray;
@property (nonatomic, retain) DLPieChart *DLPieChartView;

@end;
