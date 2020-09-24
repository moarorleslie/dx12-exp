#if 0
;
; Note: shader requires additional functionality:
;       UAVs at every shader stage
;
; shader hash: c6eef3971ba577f2819c56a39bcfcea0
;
; Buffer Definitions:
;
;
; Resource Bindings:
;
; Name                                 Type  Format         Dim      ID      HLSL Bind  Count
; ------------------------------ ---------- ------- ----------- ------- -------------- ------
; g_screenOutput                        UAV     f32          2d      U0             u2     1
;
target datalayout = "e-m:e-p:32:32-i1:32-i8:32-i16:32-i32:32-i64:64-f16:32-f32:32-f64:64-n8:16:32:64"
target triple = "dxil-ms-dx"

%"class.RWTexture2D<vector<float, 4> >" = type { <4 x float> }
%struct.RayPayload = type { i32, float }
%struct.BuiltInTriangleIntersectionAttributes = type { <2 x float> }
%dx.types.Handle = type { i8* }
%struct.DynamicCB = type { %class.matrix.float.4.4, <3 x float>, i32, <2 x float> }
%class.matrix.float.4.4 = type { [4 x <4 x float>] }

@"\01?g_screenOutput@@3V?$RWTexture2D@V?$vector@M$03@@@@A" = external constant %"class.RWTexture2D<vector<float, 4> >", align 4
@llvm.global_ctors = appending global [0 x { i32, void ()*, i8* }] zeroinitializer

; Function Attrs: nounwind
define void @"\01?Hit@@YAXURayPayload@@UBuiltInTriangleIntersectionAttributes@@@Z"(%struct.RayPayload* noalias nocapture %payload, %struct.BuiltInTriangleIntersectionAttributes* nocapture readonly %attr) #0 {
  %1 = load %"class.RWTexture2D<vector<float, 4> >", %"class.RWTexture2D<vector<float, 4> >"* @"\01?g_screenOutput@@3V?$RWTexture2D@V?$vector@M$03@@@@A", align 4
  %2 = call float @dx.op.rayTCurrent.f32(i32 154)  ; RayTCurrent()
  %3 = getelementptr inbounds %struct.RayPayload, %struct.RayPayload* %payload, i32 0, i32 1
  store float %2, float* %3, align 4, !tbaa !26
  %4 = getelementptr inbounds %struct.RayPayload, %struct.RayPayload* %payload, i32 0, i32 0
  %5 = load i32, i32* %4, align 4, !tbaa !30, !range !32
  %6 = icmp eq i32 %5, 0
  br i1 %6, label %7, label %15

; <label>:7                                       ; preds = %0
  %8 = getelementptr inbounds %struct.BuiltInTriangleIntersectionAttributes, %struct.BuiltInTriangleIntersectionAttributes* %attr, i32 0, i32 0
  %9 = load <2 x float>, <2 x float>* %8, align 4, !tbaa !33
  %10 = extractelement <2 x float> %9, i64 0
  %11 = extractelement <2 x float> %9, i64 1
  %12 = call i32 @dx.op.dispatchRaysIndex.i32(i32 145, i8 0)  ; DispatchRaysIndex(col)
  %13 = call i32 @dx.op.dispatchRaysIndex.i32(i32 145, i8 1)  ; DispatchRaysIndex(col)
  %14 = call %dx.types.Handle @"dx.op.createHandleForLib.class.RWTexture2D<vector<float, 4> >"(i32 160, %"class.RWTexture2D<vector<float, 4> >" %1)  ; CreateHandleForLib(Resource)
  call void @dx.op.textureStore.f32(i32 67, %dx.types.Handle %14, i32 %12, i32 %13, i32 undef, float %10, float %11, float 1.000000e+00, float 1.000000e+00, i8 15)  ; TextureStore(srv,coord0,coord1,coord2,value0,value1,value2,value3,mask)
  br label %15

; <label>:15                                      ; preds = %7, %0
  ret void
}

; Function Attrs: nounwind readonly
declare float @dx.op.rayTCurrent.f32(i32) #1

; Function Attrs: nounwind
declare void @dx.op.textureStore.f32(i32, %dx.types.Handle, i32, i32, i32, float, float, float, float, i8) #2

; Function Attrs: nounwind readnone
declare i32 @dx.op.dispatchRaysIndex.i32(i32, i8) #3

; Function Attrs: nounwind readonly
declare %dx.types.Handle @"dx.op.createHandleForLib.class.RWTexture2D<vector<float, 4> >"(i32, %"class.RWTexture2D<vector<float, 4> >") #1

attributes #0 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-realign-stack" "stack-protector-buffer-size"="0" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readonly }
attributes #2 = { nounwind }
attributes #3 = { nounwind readnone }

!llvm.ident = !{!0}
!dx.version = !{!1}
!dx.valver = !{!2}
!dx.shaderModel = !{!3}
!dx.resources = !{!4}
!dx.typeAnnotations = !{!8, !15}
!dx.entryPoints = !{!21, !23}

!0 = !{!"dxc 1.2"}
!1 = !{i32 1, i32 3}
!2 = !{i32 1, i32 5}
!3 = !{!"lib", i32 6, i32 3}
!4 = !{null, !5, null, null}
!5 = !{!6}
!6 = !{i32 0, %"class.RWTexture2D<vector<float, 4> >"* @"\01?g_screenOutput@@3V?$RWTexture2D@V?$vector@M$03@@@@A", !"g_screenOutput", i32 0, i32 2, i32 1, i32 2, i1 false, i1 false, i1 false, !7}
!7 = !{i32 0, i32 9}
!8 = !{i32 0, %struct.DynamicCB undef, !9}
!9 = !{i32 88, !10, !12, !13, !14}
!10 = !{i32 6, !"cameraToWorld", i32 2, !11, i32 3, i32 0, i32 7, i32 9}
!11 = !{i32 4, i32 4, i32 1}
!12 = !{i32 6, !"worldCameraPosition", i32 3, i32 64, i32 7, i32 9}
!13 = !{i32 6, !"padding", i32 3, i32 76, i32 7, i32 5}
!14 = !{i32 6, !"resolution", i32 3, i32 80, i32 7, i32 9}
!15 = !{i32 1, void (%struct.RayPayload*, %struct.BuiltInTriangleIntersectionAttributes*)* @"\01?Hit@@YAXURayPayload@@UBuiltInTriangleIntersectionAttributes@@@Z", !16}
!16 = !{!17, !19, !20}
!17 = !{i32 1, !18, !18}
!18 = !{}
!19 = !{i32 2, !18, !18}
!20 = !{i32 0, !18, !18}
!21 = !{null, !"", null, !4, !22}
!22 = !{i32 0, i64 65536}
!23 = !{void (%struct.RayPayload*, %struct.BuiltInTriangleIntersectionAttributes*)* @"\01?Hit@@YAXURayPayload@@UBuiltInTriangleIntersectionAttributes@@@Z", !"\01?Hit@@YAXURayPayload@@UBuiltInTriangleIntersectionAttributes@@@Z", null, null, !24}
!24 = !{i32 8, i32 10, i32 6, i32 8, i32 7, i32 8, i32 5, !25}
!25 = !{i32 0}
!26 = !{!27, !27, i64 0}
!27 = !{!"float", !28, i64 0}
!28 = !{!"omnipotent char", !29, i64 0}
!29 = !{!"Simple C/C++ TBAA"}
!30 = !{!31, !31, i64 0}
!31 = !{!"bool", !28, i64 0}
!32 = !{i32 0, i32 2}
!33 = !{!28, !28, i64 0}

#endif

const unsigned char g_phitShaderLib[] = {
  0x44, 0x58, 0x42, 0x43, 0x8b, 0x83, 0x41, 0xf7, 0xc1, 0x0c, 0x48, 0x62,
  0x7e, 0xaa, 0xc6, 0x9b, 0xb6, 0x7b, 0x71, 0x31, 0x01, 0x00, 0x00, 0x00,
  0x48, 0x14, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00,
  0x44, 0x00, 0x00, 0x00, 0x40, 0x01, 0x00, 0x00, 0x74, 0x0a, 0x00, 0x00,
  0x90, 0x0a, 0x00, 0x00, 0x53, 0x46, 0x49, 0x30, 0x08, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x44, 0x41, 0x54,
  0xf4, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x18, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0xa8, 0x00, 0x00, 0x00,
  0xe4, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x58, 0x00, 0x00, 0x00,
  0x00, 0x67, 0x5f, 0x73, 0x63, 0x72, 0x65, 0x65, 0x6e, 0x4f, 0x75, 0x74,
  0x70, 0x75, 0x74, 0x00, 0x01, 0x3f, 0x48, 0x69, 0x74, 0x40, 0x40, 0x59,
  0x41, 0x58, 0x55, 0x52, 0x61, 0x79, 0x50, 0x61, 0x79, 0x6c, 0x6f, 0x61,
  0x64, 0x40, 0x40, 0x55, 0x42, 0x75, 0x69, 0x6c, 0x74, 0x49, 0x6e, 0x54,
  0x72, 0x69, 0x61, 0x6e, 0x67, 0x6c, 0x65, 0x49, 0x6e, 0x74, 0x65, 0x72,
  0x73, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x41, 0x74, 0x74, 0x72, 0x69,
  0x62, 0x75, 0x74, 0x65, 0x73, 0x40, 0x40, 0x40, 0x5a, 0x00, 0x48, 0x69,
  0x74, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
  0x0a, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
  0x63, 0x00, 0x0a, 0x00, 0x02, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x53, 0x54, 0x41, 0x54,
  0x2c, 0x09, 0x00, 0x00, 0x63, 0x00, 0x06, 0x00, 0x4b, 0x02, 0x00, 0x00,
  0x44, 0x58, 0x49, 0x4c, 0x03, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x14, 0x09, 0x00, 0x00, 0x42, 0x43, 0xc0, 0xde, 0x21, 0x0c, 0x00, 0x00,
  0x42, 0x02, 0x00, 0x00, 0x0b, 0x82, 0x20, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x13, 0x00, 0x00, 0x00, 0x07, 0x81, 0x23, 0x91, 0x41, 0xc8, 0x04, 0x49,
  0x06, 0x10, 0x32, 0x39, 0x92, 0x01, 0x84, 0x0c, 0x25, 0x05, 0x08, 0x19,
  0x1e, 0x04, 0x8b, 0x62, 0x80, 0x18, 0x45, 0x02, 0x42, 0x92, 0x0b, 0x42,
  0xc4, 0x10, 0x32, 0x14, 0x38, 0x08, 0x18, 0x4b, 0x0a, 0x32, 0x62, 0x88,
  0x48, 0x90, 0x14, 0x20, 0x43, 0x46, 0x88, 0xa5, 0x00, 0x19, 0x32, 0x42,
  0xe4, 0x48, 0x0e, 0x90, 0x11, 0x23, 0xc4, 0x50, 0x41, 0x51, 0x81, 0x8c,
  0xe1, 0x83, 0xe5, 0x8a, 0x04, 0x31, 0x46, 0x06, 0x51, 0x18, 0x00, 0x00,
  0x5c, 0x00, 0x00, 0x00, 0x1b, 0x8c, 0x20, 0x00, 0x12, 0x60, 0xd9, 0x60,
  0x08, 0x02, 0xb0, 0x00, 0xd5, 0x06, 0xf0, 0x18, 0xfe, 0xff, 0xff, 0xff,
  0x7f, 0x00, 0x24, 0x82, 0x1c, 0xd2, 0x61, 0x1e, 0xc2, 0x41, 0x1c, 0xd8,
  0xa1, 0x1c, 0xda, 0x80, 0x1e, 0xc2, 0x21, 0x1d, 0xd8, 0xa1, 0x0d, 0xc6,
  0x21, 0x1c, 0xd8, 0x81, 0x1d, 0xe6, 0x01, 0x30, 0x87, 0x70, 0x60, 0x87,
  0x79, 0x28, 0x07, 0x80, 0x60, 0x87, 0x72, 0x98, 0x87, 0x79, 0x68, 0x03,
  0x78, 0x90, 0x87, 0x72, 0x18, 0x87, 0x74, 0x98, 0x87, 0x72, 0x68, 0x03,
  0x73, 0x80, 0x87, 0x76, 0x08, 0x07, 0x72, 0x00, 0xcc, 0x21, 0x1c, 0xd8,
  0x61, 0x1e, 0xca, 0x01, 0x20, 0xdc, 0xe1, 0x1d, 0xda, 0xc0, 0x1c, 0xe4,
  0x21, 0x1c, 0xda, 0xa1, 0x1c, 0xda, 0x00, 0x1e, 0xde, 0x21, 0x1d, 0xdc,
  0x81, 0x1e, 0xca, 0x41, 0x1e, 0xda, 0xa0, 0x1c, 0xd8, 0x21, 0x1d, 0xda,
  0x01, 0x30, 0x87, 0x70, 0x60, 0x87, 0x79, 0x28, 0x07, 0x80, 0x70, 0x87,
  0x77, 0x68, 0x83, 0x74, 0x70, 0x07, 0x73, 0x98, 0x87, 0x36, 0x30, 0x07,
  0x78, 0x68, 0x83, 0x76, 0x08, 0x07, 0x7a, 0x40, 0x07, 0xc0, 0x1c, 0xc2,
  0x81, 0x1d, 0xe6, 0xa1, 0x1c, 0x00, 0xc2, 0x1d, 0xde, 0xa1, 0x0d, 0xdc,
  0x21, 0x1c, 0xdc, 0x61, 0x1e, 0xda, 0xc0, 0x1c, 0xe0, 0xa1, 0x0d, 0xda,
  0x21, 0x1c, 0xe8, 0x01, 0x1d, 0x00, 0x73, 0x08, 0x07, 0x76, 0x98, 0x87,
  0x72, 0x00, 0x06, 0x77, 0x78, 0x87, 0x36, 0x90, 0x87, 0x72, 0x08, 0x07,
  0x76, 0x48, 0x87, 0x73, 0x70, 0x87, 0x36, 0x98, 0x07, 0x7a, 0x08, 0x87,
  0x71, 0x58, 0x07, 0x80, 0x98, 0x07, 0x7a, 0x08, 0x87, 0x71, 0x58, 0x87,
  0x36, 0x80, 0x07, 0x79, 0x78, 0x07, 0x7a, 0x28, 0x87, 0x71, 0xa0, 0x87,
  0x77, 0x90, 0x87, 0x36, 0x10, 0x87, 0x7a, 0x30, 0x07, 0x73, 0x28, 0x07,
  0x79, 0x68, 0x83, 0x79, 0x48, 0x07, 0x7d, 0x28, 0x07, 0x00, 0x0e, 0x00,
  0xa2, 0x1e, 0xdc, 0x61, 0x1e, 0xc2, 0xc1, 0x1c, 0xca, 0xa1, 0x0d, 0xcc,
  0x01, 0x1e, 0xda, 0xa0, 0x1d, 0xc2, 0x81, 0x1e, 0xd0, 0x01, 0x30, 0x87,
  0x70, 0x60, 0x87, 0x79, 0x28, 0x07, 0x80, 0xa8, 0x87, 0x79, 0x28, 0x87,
  0x36, 0x98, 0x87, 0x77, 0x30, 0x07, 0x7a, 0x68, 0x03, 0x73, 0x60, 0x87,
  0x77, 0x08, 0x07, 0x7a, 0x00, 0xcc, 0x21, 0x1c, 0xd8, 0x61, 0x1e, 0xca,
  0x01, 0xd8, 0x60, 0x10, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x12, 0x50,
  0x6d, 0x20, 0x8a, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x69, 0x83, 0x61,
  0xfc, 0xff, 0xff, 0xff, 0xff, 0x00, 0x48, 0x00, 0x05, 0x00, 0x00, 0x00,
  0x49, 0x18, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x13, 0x86, 0x40, 0x18,
  0x26, 0x04, 0xc4, 0x84, 0xa0, 0x98, 0x10, 0x18, 0x00, 0x00, 0x00, 0x00,
  0x89, 0x20, 0x00, 0x00, 0x4d, 0x00, 0x00, 0x00, 0x32, 0x22, 0x88, 0x09,
  0x20, 0x64, 0x85, 0x04, 0x13, 0x23, 0xa4, 0x84, 0x04, 0x13, 0x23, 0xe3,
  0x84, 0xa1, 0x90, 0x14, 0x12, 0x4c, 0x8c, 0x8c, 0x0b, 0x84, 0xc4, 0x4c,
  0x10, 0x94, 0xc1, 0x0c, 0xc0, 0x30, 0x02, 0x01, 0xcc, 0x44, 0x06, 0xe3,
  0xc0, 0x0e, 0xe1, 0x30, 0x0f, 0xf3, 0xe0, 0x06, 0xb2, 0x70, 0x0b, 0xb4,
  0x50, 0x0e, 0xf8, 0x40, 0x0f, 0xf5, 0x20, 0x0f, 0xe5, 0x20, 0x07, 0xa4,
  0xc0, 0x07, 0xf6, 0x50, 0x0e, 0xe3, 0x40, 0x0f, 0xef, 0x20, 0x0f, 0x7c,
  0x60, 0x0e, 0xec, 0xf0, 0x0e, 0xe1, 0x40, 0x0f, 0x6c, 0x00, 0x06, 0x74,
  0xe0, 0x07, 0x60, 0xe0, 0x07, 0x28, 0x08, 0x48, 0x98, 0x23, 0x00, 0x83,
  0x11, 0x80, 0x12, 0x14, 0x64, 0xcc, 0x11, 0x20, 0x84, 0x98, 0x81, 0x38,
  0x92, 0x04, 0x50, 0x68, 0xb9, 0x48, 0x9a, 0x22, 0x4a, 0x98, 0xfc, 0x15,
  0xc0, 0x52, 0x00, 0x5b, 0x1c, 0x60, 0x40, 0x02, 0x01, 0x50, 0x33, 0x8c,
  0x20, 0x00, 0xc7, 0x06, 0xd2, 0x14, 0x51, 0xc2, 0xe4, 0x6f, 0x14, 0xb2,
  0x4c, 0x62, 0xd3, 0x46, 0x08, 0xd0, 0x18, 0x0b, 0x21, 0x36, 0x13, 0x11,
  0x49, 0x84, 0x30, 0x21, 0x4e, 0xa3, 0x4d, 0x53, 0x84, 0x04, 0xd4, 0x44,
  0x48, 0x28, 0x78, 0x08, 0x2a, 0x43, 0xe1, 0x44, 0x24, 0x15, 0x01, 0x20,
  0x88, 0xba, 0x67, 0xb8, 0xfc, 0x09, 0x7b, 0x08, 0xc9, 0x0f, 0x81, 0x66,
  0x58, 0x08, 0x14, 0x24, 0x65, 0x29, 0x08, 0x8b, 0x20, 0x08, 0x00, 0x00,
  0x00, 0x84, 0xae, 0x32, 0x10, 0x04, 0x42, 0x59, 0x19, 0x2c, 0x42, 0xa0,
  0x6d, 0x20, 0x60, 0x8e, 0x20, 0x38, 0x33, 0x90, 0xa6, 0x88, 0x12, 0x26,
  0x7f, 0x05, 0xb0, 0x29, 0x02, 0x04, 0xa4, 0x31, 0x34, 0x41, 0x20, 0x16,
  0x22, 0x02, 0x26, 0xc4, 0x69, 0xd8, 0x29, 0xa2, 0x84, 0x89, 0x8a, 0x08,
  0x14, 0x10, 0x49, 0x10, 0x9c, 0x25, 0x2c, 0x80, 0x24, 0xf9, 0x0c, 0x30,
  0x45, 0xc8, 0xe5, 0x17, 0x8b, 0x03, 0x4c, 0x3e, 0xee, 0xe3, 0x28, 0x00,
  0x87, 0x11, 0x06, 0xe0, 0x20, 0x69, 0x8a, 0x28, 0x61, 0xf2, 0x3b, 0xac,
  0x01, 0x18, 0x44, 0xe0, 0x36, 0x44, 0x84, 0x22, 0xf1, 0xcc, 0x11, 0x80,
  0x02, 0x00, 0x00, 0x00, 0x13, 0x14, 0x72, 0xc0, 0x87, 0x74, 0x60, 0x87,
  0x36, 0x68, 0x87, 0x79, 0x68, 0x03, 0x72, 0xc0, 0x87, 0x0d, 0xaf, 0x50,
  0x0e, 0x6d, 0xd0, 0x0e, 0x7a, 0x50, 0x0e, 0x6d, 0x00, 0x0f, 0x7a, 0x30,
  0x07, 0x72, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x71, 0xa0,
  0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x78, 0xa0, 0x07, 0x73, 0x20,
  0x07, 0x6d, 0x90, 0x0e, 0x71, 0x60, 0x07, 0x7a, 0x30, 0x07, 0x72, 0xd0,
  0x06, 0xe9, 0x30, 0x07, 0x72, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90,
  0x0e, 0x76, 0x40, 0x07, 0x7a, 0x60, 0x07, 0x74, 0xd0, 0x06, 0xe6, 0x10,
  0x07, 0x76, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x60, 0x0e, 0x73, 0x20,
  0x07, 0x7a, 0x30, 0x07, 0x72, 0xd0, 0x06, 0xe6, 0x60, 0x07, 0x74, 0xa0,
  0x07, 0x76, 0x40, 0x07, 0x6d, 0xe0, 0x0e, 0x78, 0xa0, 0x07, 0x71, 0x60,
  0x07, 0x7a, 0x30, 0x07, 0x72, 0xa0, 0x07, 0x76, 0x40, 0x07, 0x3a, 0x0f,
  0x84, 0x90, 0x21, 0x23, 0x45, 0x44, 0x00, 0xca, 0x00, 0x80, 0xb9, 0x82,
  0x26, 0x18, 0xf2, 0x48, 0x40, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x30, 0xe4, 0xa1, 0x80, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x60, 0xc8, 0x73, 0x01, 0x01, 0x30, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xc0, 0x90, 0x27, 0x03, 0x02, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x21, 0xcf, 0x06, 0x04, 0x80, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x59, 0x20, 0x00, 0x00, 0x00,
  0x13, 0x00, 0x00, 0x00, 0x32, 0x1e, 0x98, 0x18, 0x19, 0x11, 0x4c, 0x90,
  0x8c, 0x09, 0x26, 0x47, 0xc6, 0x04, 0x43, 0x22, 0x0b, 0x10, 0x10, 0x81,
  0xbc, 0x11, 0x00, 0x22, 0x4a, 0xa0, 0x0c, 0x46, 0x00, 0x8a, 0xa1, 0x08,
  0x4a, 0xa2, 0x10, 0xca, 0xa1, 0x40, 0x0a, 0x36, 0xa0, 0x00, 0x03, 0x0a,
  0x33, 0xa0, 0x14, 0x0a, 0x34, 0xa0, 0x20, 0x8a, 0x82, 0x96, 0x11, 0x00,
  0x6a, 0x66, 0x00, 0x08, 0x9a, 0x01, 0x20, 0x61, 0x06, 0x80, 0xbe, 0x19,
  0x00, 0x1a, 0x67, 0x00, 0x28, 0x98, 0x01, 0x00, 0x79, 0x18, 0x00, 0x00,
  0x9d, 0x00, 0x00, 0x00, 0x1a, 0x03, 0x4c, 0x90, 0x46, 0x02, 0x13, 0xc4,
  0x83, 0x0c, 0x6f, 0x0c, 0x24, 0xc6, 0x45, 0x66, 0x43, 0x10, 0x4c, 0x10,
  0x88, 0x64, 0x82, 0x40, 0x28, 0x1b, 0x84, 0x81, 0x98, 0x20, 0x10, 0xcb,
  0x06, 0xc1, 0x30, 0x38, 0xb0, 0xa5, 0x89, 0x4d, 0x10, 0x08, 0x66, 0xc3,
  0x80, 0x24, 0xc4, 0x04, 0x61, 0x00, 0xe8, 0x9c, 0x7d, 0xcd, 0x8d, 0xc9,
  0x95, 0x95, 0xb9, 0x3d, 0xd5, 0xd1, 0xc1, 0xd5, 0xd1, 0x4d, 0x10, 0x88,
  0x66, 0x82, 0xe0, 0x21, 0x13, 0x04, 0xc2, 0xd9, 0x20, 0x18, 0xcf, 0x86,
  0xc5, 0x58, 0x18, 0xa3, 0x19, 0x1a, 0xc7, 0x71, 0xa0, 0x0d, 0x41, 0xb4,
  0x81, 0x00, 0x24, 0x00, 0x98, 0x20, 0x7c, 0xdd, 0x04, 0x81, 0x78, 0x18,
  0xa0, 0x4d, 0x10, 0x08, 0x68, 0x83, 0x91, 0x58, 0x84, 0x71, 0x55, 0x1b,
  0x84, 0x0a, 0x9b, 0x20, 0x08, 0xdc, 0x04, 0x81, 0x88, 0x36, 0x18, 0x89,
  0x45, 0x18, 0xd7, 0x33, 0x41, 0x08, 0xbe, 0x0d, 0x82, 0xd1, 0x6d, 0x08,
  0xbc, 0x0d, 0x82, 0xf1, 0x6d, 0x18, 0x36, 0x0e, 0x0c, 0x26, 0x08, 0x63,
  0xe0, 0x4d, 0x10, 0x08, 0x89, 0xcd, 0x58, 0x58, 0x5b, 0x99, 0x5c, 0x18,
  0xd5, 0xdb, 0xd5, 0x9b, 0x1c, 0x1b, 0xd9, 0x86, 0xa1, 0xaa, 0x86, 0x0d,
  0x48, 0x42, 0x06, 0x4d, 0x19, 0x10, 0xc6, 0xf5, 0x70, 0xba, 0x7b, 0x93,
  0x63, 0x23, 0x1b, 0x0a, 0x6b, 0x2b, 0x93, 0x0b, 0x83, 0x7a, 0x9b, 0x4b,
  0xa3, 0x4b, 0x7b, 0x73, 0x9b, 0x20, 0x10, 0xd3, 0x06, 0x23, 0x39, 0x03,
  0x02, 0x0d, 0xae, 0x87, 0x07, 0x5c, 0x18, 0x19, 0x59, 0x9a, 0xdb, 0xd9,
  0x04, 0x81, 0xa0, 0x26, 0x08, 0x44, 0xb5, 0xc1, 0x48, 0xd4, 0x80, 0x58,
  0x83, 0x8b, 0x0d, 0xa8, 0xc8, 0x95, 0xcd, 0xbd, 0xb1, 0xd5, 0xd1, 0xa5,
  0xbd, 0xb9, 0x4d, 0x10, 0x08, 0x6b, 0x83, 0x91, 0xb8, 0x01, 0xf1, 0x06,
  0xd7, 0xb3, 0xa1, 0x18, 0x03, 0x33, 0x48, 0x83, 0x36, 0x80, 0x83, 0x09,
  0x42, 0xa3, 0x4d, 0x10, 0x88, 0x8b, 0xcb, 0xd4, 0x5a, 0x1a, 0xdc, 0x14,
  0x5a, 0x18, 0x59, 0x9a, 0xdb, 0xd9, 0x06, 0x23, 0xa1, 0x03, 0xc2, 0xb8,
  0x06, 0x1e, 0x52, 0x61, 0x79, 0x48, 0x69, 0x74, 0x54, 0x1b, 0x8c, 0xc4,
  0x0e, 0x88, 0xea, 0x7a, 0x36, 0x0c, 0x73, 0x50, 0x07, 0x77, 0x30, 0x41,
  0x80, 0x36, 0x32, 0x62, 0x61, 0x72, 0x79, 0x63, 0x65, 0x6e, 0x74, 0x72,
  0x69, 0x63, 0x73, 0x1b, 0x8c, 0x44, 0x0f, 0x08, 0xe3, 0x7a, 0x36, 0x08,
  0x73, 0xb0, 0x07, 0x1b, 0x16, 0x83, 0xca, 0xb4, 0x30, 0x10, 0x83, 0x38,
  0x90, 0x03, 0x3c, 0xc8, 0x03, 0x3e, 0x98, 0x20, 0x4c, 0xc2, 0x06, 0x60,
  0xc3, 0x30, 0xfc, 0xc1, 0x1f, 0x6c, 0x18, 0x9a, 0x3f, 0xf8, 0x83, 0x0d,
  0x83, 0xf1, 0x07, 0x7f, 0xb0, 0x61, 0x00, 0x85, 0x50, 0x10, 0x85, 0x0d,
  0xc3, 0xe0, 0x07, 0xa3, 0x40, 0x60, 0x82, 0x40, 0x06, 0xc7, 0x06, 0xc1,
  0x30, 0x85, 0x0d, 0x05, 0x50, 0x0a, 0xc0, 0x74, 0x0a, 0x0c, 0x85, 0x80,
  0x1f, 0xa4, 0x34, 0x3a, 0x20, 0xa0, 0xac, 0x20, 0xac, 0x2a, 0xa9, 0xb0,
  0x3c, 0xa8, 0xb0, 0x3c, 0xb6, 0xb7, 0x30, 0x32, 0x20, 0xa0, 0x2a, 0xa1,
  0xba, 0x34, 0x36, 0xba, 0x24, 0x37, 0x2a, 0xb9, 0xb4, 0x30, 0xb7, 0x33,
  0xb6, 0xb2, 0x24, 0x37, 0xba, 0x32, 0xb9, 0xb9, 0xb2, 0x31, 0xba, 0xb4,
  0x37, 0xb7, 0x20, 0x3a, 0x3a, 0xb9, 0x34, 0xb1, 0x3a, 0xba, 0xb2, 0x39,
  0x20, 0x20, 0x20, 0xad, 0x09, 0x02, 0x81, 0x6d, 0x08, 0x8c, 0x0d, 0xc8,
  0x1c, 0xa8, 0x42, 0x32, 0x07, 0xd7, 0x1c, 0xb0, 0xc1, 0x2a, 0x6c, 0x28,
  0xfc, 0x20, 0x15, 0x00, 0x80, 0x15, 0xaa, 0xb0, 0xb1, 0xd9, 0xb5, 0xb9,
  0xa4, 0x91, 0x95, 0xb9, 0xd1, 0x4d, 0x09, 0x82, 0x2a, 0x64, 0x78, 0x2e,
  0x76, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x53, 0x02, 0xa2, 0x09, 0x19,
  0x9e, 0x8b, 0x5d, 0x18, 0x9b, 0x5d, 0x99, 0xdc, 0x94, 0xc0, 0xa8, 0x43,
  0x86, 0xe7, 0x32, 0x87, 0x16, 0x46, 0x56, 0x26, 0xd7, 0xf4, 0x46, 0x56,
  0xc6, 0x36, 0x25, 0x48, 0xca, 0x90, 0xe1, 0xb9, 0xc8, 0x95, 0xcd, 0xbd,
  0xd5, 0xc9, 0x8d, 0x95, 0xcd, 0x4d, 0x09, 0xa4, 0x4a, 0x64, 0x78, 0x2e,
  0x74, 0x79, 0x70, 0x65, 0x41, 0x6e, 0x6e, 0x6f, 0x74, 0x61, 0x74, 0x69,
  0x6f, 0x6e, 0x73, 0x53, 0x04, 0x3e, 0x18, 0x85, 0x3a, 0x64, 0x78, 0x2e,
  0x65, 0x6e, 0x74, 0x72, 0x79, 0x50, 0x6f, 0x69, 0x6e, 0x74, 0x73, 0x53,
  0x84, 0x53, 0x60, 0x05, 0x00, 0x00, 0x00, 0x00, 0x79, 0x18, 0x00, 0x00,
  0x4c, 0x00, 0x00, 0x00, 0x33, 0x08, 0x80, 0x1c, 0xc4, 0xe1, 0x1c, 0x66,
  0x14, 0x01, 0x3d, 0x88, 0x43, 0x38, 0x84, 0xc3, 0x8c, 0x42, 0x80, 0x07,
  0x79, 0x78, 0x07, 0x73, 0x98, 0x71, 0x0c, 0xe6, 0x00, 0x0f, 0xed, 0x10,
  0x0e, 0xf4, 0x80, 0x0e, 0x33, 0x0c, 0x42, 0x1e, 0xc2, 0xc1, 0x1d, 0xce,
  0xa1, 0x1c, 0x66, 0x30, 0x05, 0x3d, 0x88, 0x43, 0x38, 0x84, 0x83, 0x1b,
  0xcc, 0x03, 0x3d, 0xc8, 0x43, 0x3d, 0x8c, 0x03, 0x3d, 0xcc, 0x78, 0x8c,
  0x74, 0x70, 0x07, 0x7b, 0x08, 0x07, 0x79, 0x48, 0x87, 0x70, 0x70, 0x07,
  0x7a, 0x70, 0x03, 0x76, 0x78, 0x87, 0x70, 0x20, 0x87, 0x19, 0xcc, 0x11,
  0x0e, 0xec, 0x90, 0x0e, 0xe1, 0x30, 0x0f, 0x6e, 0x30, 0x0f, 0xe3, 0xf0,
  0x0e, 0xf0, 0x50, 0x0e, 0x33, 0x10, 0xc4, 0x1d, 0xde, 0x21, 0x1c, 0xd8,
  0x21, 0x1d, 0xc2, 0x61, 0x1e, 0x66, 0x30, 0x89, 0x3b, 0xbc, 0x83, 0x3b,
  0xd0, 0x43, 0x39, 0xb4, 0x03, 0x3c, 0xbc, 0x83, 0x3c, 0x84, 0x03, 0x3b,
  0xcc, 0xf0, 0x14, 0x76, 0x60, 0x07, 0x7b, 0x68, 0x07, 0x37, 0x68, 0x87,
  0x72, 0x68, 0x07, 0x37, 0x80, 0x87, 0x70, 0x90, 0x87, 0x70, 0x60, 0x07,
  0x76, 0x28, 0x07, 0x76, 0xf8, 0x05, 0x76, 0x78, 0x87, 0x77, 0x80, 0x87,
  0x5f, 0x08, 0x87, 0x71, 0x18, 0x87, 0x72, 0x98, 0x87, 0x79, 0x98, 0x81,
  0x2c, 0xee, 0xf0, 0x0e, 0xee, 0xe0, 0x0e, 0xf5, 0xc0, 0x0e, 0xec, 0x30,
  0x03, 0x62, 0xc8, 0xa1, 0x1c, 0xe4, 0xa1, 0x1c, 0xcc, 0xa1, 0x1c, 0xe4,
  0xa1, 0x1c, 0xdc, 0x61, 0x1c, 0xca, 0x21, 0x1c, 0xc4, 0x81, 0x1d, 0xca,
  0x61, 0x06, 0xd6, 0x90, 0x43, 0x39, 0xc8, 0x43, 0x39, 0x98, 0x43, 0x39,
  0xc8, 0x43, 0x39, 0xb8, 0xc3, 0x38, 0x94, 0x43, 0x38, 0x88, 0x03, 0x3b,
  0x94, 0xc3, 0x2f, 0xbc, 0x83, 0x3c, 0xfc, 0x82, 0x3b, 0xd4, 0x03, 0x3b,
  0xb0, 0xc3, 0x8c, 0xcc, 0x21, 0x07, 0x7c, 0x70, 0x03, 0x74, 0x60, 0x07,
  0x37, 0x90, 0x87, 0x72, 0x98, 0x87, 0x77, 0xa8, 0x07, 0x79, 0x18, 0x87,
  0x72, 0x70, 0x83, 0x70, 0xa0, 0x07, 0x7a, 0x90, 0x87, 0x74, 0x10, 0x87,
  0x7a, 0xa0, 0x87, 0x72, 0x00, 0x00, 0x00, 0x00, 0x71, 0x20, 0x00, 0x00,
  0x3d, 0x00, 0x00, 0x00, 0x25, 0x10, 0x0a, 0x81, 0x1f, 0x32, 0x4d, 0x07,
  0x02, 0xb3, 0x41, 0x6c, 0x55, 0x1a, 0xce, 0x43, 0xc3, 0x79, 0xf6, 0x3b,
  0x4c, 0x06, 0x02, 0xab, 0xc2, 0x7a, 0x9a, 0x4d, 0x4f, 0xba, 0xa9, 0xf2,
  0x74, 0xd8, 0x7d, 0x66, 0x97, 0x93, 0x6e, 0x7a, 0x59, 0x3e, 0x2f, 0x8f,
  0xe9, 0xe9, 0xb7, 0x3b, 0x48, 0xa7, 0xcb, 0xd3, 0xe2, 0x3a, 0xbd, 0x3c,
  0x07, 0x02, 0x81, 0xda, 0x02, 0xa8, 0x83, 0xc0, 0xef, 0xfc, 0x9d, 0x8f,
  0xe5, 0xe5, 0xb2, 0xfb, 0x59, 0xa7, 0xc3, 0xeb, 0x74, 0x20, 0x70, 0x66,
  0xfd, 0x91, 0xa4, 0x57, 0x6a, 0x19, 0x4f, 0xaf, 0xcb, 0xcb, 0x32, 0x22,
  0xd0, 0xfa, 0x23, 0xd9, 0xcb, 0x63, 0xfa, 0x5b, 0x0e, 0x6c, 0x92, 0x60,
  0x33, 0x20, 0x10, 0x08, 0x0c, 0x96, 0x41, 0x1f, 0x90, 0xf1, 0xae, 0x37,
  0xdc, 0x35, 0x96, 0x97, 0xc3, 0xf4, 0x32, 0x32, 0xec, 0x26, 0xb3, 0xcb,
  0xc6, 0xb7, 0x9c, 0x99, 0x16, 0xbb, 0xc6, 0xec, 0xf0, 0x7c, 0xee, 0x92,
  0x5e, 0xa9, 0x65, 0x3c, 0xbd, 0x2e, 0x2f, 0xcb, 0x88, 0x3c, 0x7b, 0x79,
  0x4c, 0x7f, 0xcb, 0x79, 0x66, 0xf6, 0x3b, 0x4c, 0x67, 0x81, 0x68, 0x3e,
  0x90, 0xcf, 0x0a, 0xb6, 0xe1, 0xf2, 0x9d, 0xc7, 0x1f, 0x10, 0xe9, 0x01,
  0x26, 0xe1, 0x58, 0x01, 0x4c, 0x12, 0x9b, 0x81, 0xb8, 0x7c, 0xe4, 0xb6,
  0x6d, 0xa0, 0x1a, 0x2e, 0xdf, 0x79, 0xfc, 0x08, 0xc0, 0x5a, 0x8e, 0x8a,
  0x22, 0xa2, 0x99, 0xfc, 0xe2, 0xb6, 0x8d, 0xc0, 0x1a, 0x2e, 0xdf, 0x79,
  0xfc, 0x89, 0xb8, 0x26, 0x2a, 0x22, 0xd8, 0xc9, 0x89, 0x08, 0xbf, 0xb8,
  0x6d, 0x0b, 0x88, 0x96, 0xa5, 0x62, 0x7c, 0x63, 0x71, 0x02, 0x60, 0xf9,
  0x85, 0xc9, 0x89, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x48, 0x41, 0x53, 0x48, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xc6, 0xee, 0xf3, 0x97, 0x1b, 0xa5, 0x77, 0xf2, 0x81, 0x9c, 0x56, 0xa3,
  0x9b, 0xcf, 0xce, 0xa0, 0x44, 0x58, 0x49, 0x4c, 0xb0, 0x09, 0x00, 0x00,
  0x63, 0x00, 0x06, 0x00, 0x6c, 0x02, 0x00, 0x00, 0x44, 0x58, 0x49, 0x4c,
  0x03, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x98, 0x09, 0x00, 0x00,
  0x42, 0x43, 0xc0, 0xde, 0x21, 0x0c, 0x00, 0x00, 0x63, 0x02, 0x00, 0x00,
  0x0b, 0x82, 0x20, 0x00, 0x02, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00,
  0x07, 0x81, 0x23, 0x91, 0x41, 0xc8, 0x04, 0x49, 0x06, 0x10, 0x32, 0x39,
  0x92, 0x01, 0x84, 0x0c, 0x25, 0x05, 0x08, 0x19, 0x1e, 0x04, 0x8b, 0x62,
  0x80, 0x18, 0x45, 0x02, 0x42, 0x92, 0x0b, 0x42, 0xc4, 0x10, 0x32, 0x14,
  0x38, 0x08, 0x18, 0x4b, 0x0a, 0x32, 0x62, 0x88, 0x48, 0x90, 0x14, 0x20,
  0x43, 0x46, 0x88, 0xa5, 0x00, 0x19, 0x32, 0x42, 0xe4, 0x48, 0x0e, 0x90,
  0x11, 0x23, 0xc4, 0x50, 0x41, 0x51, 0x81, 0x8c, 0xe1, 0x83, 0xe5, 0x8a,
  0x04, 0x31, 0x46, 0x06, 0x51, 0x18, 0x00, 0x00, 0x5c, 0x00, 0x00, 0x00,
  0x1b, 0x8c, 0x20, 0x00, 0x12, 0x60, 0xd9, 0x60, 0x08, 0x02, 0xb0, 0x00,
  0xd5, 0x06, 0xf0, 0x18, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x24, 0x82,
  0x1c, 0xd2, 0x61, 0x1e, 0xc2, 0x41, 0x1c, 0xd8, 0xa1, 0x1c, 0xda, 0x80,
  0x1e, 0xc2, 0x21, 0x1d, 0xd8, 0xa1, 0x0d, 0xc6, 0x21, 0x1c, 0xd8, 0x81,
  0x1d, 0xe6, 0x01, 0x30, 0x87, 0x70, 0x60, 0x87, 0x79, 0x28, 0x07, 0x80,
  0x60, 0x87, 0x72, 0x98, 0x87, 0x79, 0x68, 0x03, 0x78, 0x90, 0x87, 0x72,
  0x18, 0x87, 0x74, 0x98, 0x87, 0x72, 0x68, 0x03, 0x73, 0x80, 0x87, 0x76,
  0x08, 0x07, 0x72, 0x00, 0xcc, 0x21, 0x1c, 0xd8, 0x61, 0x1e, 0xca, 0x01,
  0x20, 0xdc, 0xe1, 0x1d, 0xda, 0xc0, 0x1c, 0xe4, 0x21, 0x1c, 0xda, 0xa1,
  0x1c, 0xda, 0x00, 0x1e, 0xde, 0x21, 0x1d, 0xdc, 0x81, 0x1e, 0xca, 0x41,
  0x1e, 0xda, 0xa0, 0x1c, 0xd8, 0x21, 0x1d, 0xda, 0x01, 0x30, 0x87, 0x70,
  0x60, 0x87, 0x79, 0x28, 0x07, 0x80, 0x70, 0x87, 0x77, 0x68, 0x83, 0x74,
  0x70, 0x07, 0x73, 0x98, 0x87, 0x36, 0x30, 0x07, 0x78, 0x68, 0x83, 0x76,
  0x08, 0x07, 0x7a, 0x40, 0x07, 0xc0, 0x1c, 0xc2, 0x81, 0x1d, 0xe6, 0xa1,
  0x1c, 0x00, 0xc2, 0x1d, 0xde, 0xa1, 0x0d, 0xdc, 0x21, 0x1c, 0xdc, 0x61,
  0x1e, 0xda, 0xc0, 0x1c, 0xe0, 0xa1, 0x0d, 0xda, 0x21, 0x1c, 0xe8, 0x01,
  0x1d, 0x00, 0x73, 0x08, 0x07, 0x76, 0x98, 0x87, 0x72, 0x00, 0x06, 0x77,
  0x78, 0x87, 0x36, 0x90, 0x87, 0x72, 0x08, 0x07, 0x76, 0x48, 0x87, 0x73,
  0x70, 0x87, 0x36, 0x98, 0x07, 0x7a, 0x08, 0x87, 0x71, 0x58, 0x07, 0x80,
  0x98, 0x07, 0x7a, 0x08, 0x87, 0x71, 0x58, 0x87, 0x36, 0x80, 0x07, 0x79,
  0x78, 0x07, 0x7a, 0x28, 0x87, 0x71, 0xa0, 0x87, 0x77, 0x90, 0x87, 0x36,
  0x10, 0x87, 0x7a, 0x30, 0x07, 0x73, 0x28, 0x07, 0x79, 0x68, 0x83, 0x79,
  0x48, 0x07, 0x7d, 0x28, 0x07, 0x00, 0x0e, 0x00, 0xa2, 0x1e, 0xdc, 0x61,
  0x1e, 0xc2, 0xc1, 0x1c, 0xca, 0xa1, 0x0d, 0xcc, 0x01, 0x1e, 0xda, 0xa0,
  0x1d, 0xc2, 0x81, 0x1e, 0xd0, 0x01, 0x30, 0x87, 0x70, 0x60, 0x87, 0x79,
  0x28, 0x07, 0x80, 0xa8, 0x87, 0x79, 0x28, 0x87, 0x36, 0x98, 0x87, 0x77,
  0x30, 0x07, 0x7a, 0x68, 0x03, 0x73, 0x60, 0x87, 0x77, 0x08, 0x07, 0x7a,
  0x00, 0xcc, 0x21, 0x1c, 0xd8, 0x61, 0x1e, 0xca, 0x01, 0xd8, 0x60, 0x10,
  0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x12, 0x50, 0x6d, 0x20, 0x8a, 0xff,
  0xff, 0xff, 0xff, 0x1f, 0x00, 0x69, 0x83, 0x61, 0xfc, 0xff, 0xff, 0xff,
  0xff, 0x00, 0x48, 0x00, 0x05, 0x00, 0x00, 0x00, 0x49, 0x18, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x13, 0x86, 0x40, 0x18, 0x26, 0x04, 0xc4, 0x84,
  0xa0, 0x98, 0x10, 0x18, 0x00, 0x00, 0x00, 0x00, 0x89, 0x20, 0x00, 0x00,
  0x46, 0x00, 0x00, 0x00, 0x32, 0x22, 0x88, 0x09, 0x20, 0x64, 0x85, 0x04,
  0x13, 0x23, 0xa4, 0x84, 0x04, 0x13, 0x23, 0xe3, 0x84, 0xa1, 0x90, 0x14,
  0x12, 0x4c, 0x8c, 0x8c, 0x0b, 0x84, 0xc4, 0x4c, 0x10, 0xa0, 0xc1, 0x0c,
  0xc0, 0x30, 0x02, 0x01, 0xcc, 0x44, 0x06, 0xe3, 0xc0, 0x0e, 0xe1, 0x30,
  0x0f, 0xf3, 0xe0, 0x06, 0xb2, 0x70, 0x0b, 0xb4, 0x50, 0x0e, 0xf8, 0x40,
  0x0f, 0xf5, 0x20, 0x0f, 0xe5, 0x20, 0x07, 0xa4, 0xc0, 0x07, 0xf6, 0x50,
  0x0e, 0xe3, 0x40, 0x0f, 0xef, 0x20, 0x0f, 0x7c, 0x60, 0x0e, 0xec, 0xf0,
  0x0e, 0xe1, 0x40, 0x0f, 0x6c, 0x00, 0x06, 0x74, 0xe0, 0x07, 0x60, 0xe0,
  0x07, 0x28, 0x08, 0x48, 0x98, 0x23, 0x00, 0x83, 0x11, 0x80, 0x12, 0x14,
  0x64, 0xcc, 0x11, 0x20, 0x84, 0x98, 0x81, 0x38, 0x92, 0x04, 0x50, 0x68,
  0xb9, 0x48, 0x9a, 0x22, 0x4a, 0x98, 0xfc, 0x15, 0xc0, 0x52, 0x00, 0x5b,
  0x1c, 0x60, 0x40, 0x02, 0x01, 0x50, 0x33, 0x8c, 0x20, 0x00, 0xc7, 0x06,
  0xd2, 0x14, 0x51, 0xc2, 0xe4, 0x6f, 0x14, 0xb2, 0x4c, 0x62, 0xd3, 0x46,
  0x08, 0xd0, 0x18, 0x0b, 0x21, 0x36, 0x13, 0x11, 0x49, 0x84, 0x30, 0x21,
  0x4e, 0xa3, 0x4d, 0x53, 0x84, 0x04, 0xd4, 0x44, 0x48, 0x28, 0x78, 0x08,
  0x2a, 0x43, 0xe1, 0x44, 0x24, 0x15, 0x01, 0x20, 0x88, 0xba, 0x67, 0xb8,
  0xfc, 0x09, 0x7b, 0x08, 0xc9, 0x0f, 0x81, 0x66, 0x58, 0x08, 0x14, 0x24,
  0x65, 0x29, 0x08, 0x8b, 0x20, 0x08, 0x00, 0x00, 0x00, 0x84, 0xae, 0x32,
  0x10, 0x04, 0x42, 0x59, 0x19, 0x2c, 0x42, 0xa0, 0x6d, 0x20, 0x60, 0x8e,
  0x20, 0x48, 0x82, 0xe0, 0x2c, 0x61, 0x01, 0x24, 0xc9, 0x67, 0x80, 0x29,
  0x42, 0x2e, 0xbf, 0x58, 0x1c, 0x60, 0xf2, 0x71, 0x1f, 0x47, 0xc1, 0x37,
  0x8c, 0x30, 0x00, 0x07, 0x49, 0x53, 0x44, 0x09, 0x93, 0xdf, 0x61, 0x0d,
  0xc0, 0x20, 0x02, 0xb7, 0x21, 0x02, 0x0c, 0x89, 0x67, 0x8e, 0x00, 0x14,
  0x08, 0x20, 0x62, 0x0a, 0x80, 0x1e, 0x00, 0x00, 0x13, 0x14, 0x72, 0xc0,
  0x87, 0x74, 0x60, 0x87, 0x36, 0x68, 0x87, 0x79, 0x68, 0x03, 0x72, 0xc0,
  0x87, 0x0d, 0xaf, 0x50, 0x0e, 0x6d, 0xd0, 0x0e, 0x7a, 0x50, 0x0e, 0x6d,
  0x00, 0x0f, 0x7a, 0x30, 0x07, 0x72, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d,
  0x90, 0x0e, 0x71, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x78,
  0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x71, 0x60, 0x07, 0x7a,
  0x30, 0x07, 0x72, 0xd0, 0x06, 0xe9, 0x30, 0x07, 0x72, 0xa0, 0x07, 0x73,
  0x20, 0x07, 0x6d, 0x90, 0x0e, 0x76, 0x40, 0x07, 0x7a, 0x60, 0x07, 0x74,
  0xd0, 0x06, 0xe6, 0x10, 0x07, 0x76, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d,
  0x60, 0x0e, 0x73, 0x20, 0x07, 0x7a, 0x30, 0x07, 0x72, 0xd0, 0x06, 0xe6,
  0x60, 0x07, 0x74, 0xa0, 0x07, 0x76, 0x40, 0x07, 0x6d, 0xe0, 0x0e, 0x78,
  0xa0, 0x07, 0x71, 0x60, 0x07, 0x7a, 0x30, 0x07, 0x72, 0xa0, 0x07, 0x76,
  0x40, 0x07, 0x3a, 0x0f, 0x84, 0x90, 0x21, 0x23, 0x45, 0x44, 0x00, 0xca,
  0x00, 0x80, 0xb9, 0xc2, 0x26, 0x18, 0xf2, 0x48, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xe4, 0xa1, 0x80, 0x00, 0x10,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0xc8, 0x73, 0x01, 0x01,
  0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x90, 0x27, 0x03,
  0x02, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x21, 0xcf,
  0x06, 0x04, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x59,
  0x20, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x32, 0x1e, 0x98, 0x14,
  0x19, 0x11, 0x4c, 0x90, 0x8c, 0x09, 0x26, 0x47, 0xc6, 0x04, 0x43, 0x22,
  0x4a, 0xa0, 0x0c, 0x4a, 0xa1, 0x18, 0x46, 0x00, 0x8a, 0xa0, 0x24, 0x0a,
  0x36, 0xa0, 0x10, 0xca, 0xa1, 0x00, 0x03, 0x0a, 0x33, 0xa0, 0x40, 0x03,
  0x0a, 0xa2, 0x28, 0x68, 0x1c, 0x01, 0x20, 0x6f, 0x04, 0x80, 0xc6, 0x02,
  0x04, 0x44, 0x20, 0x71, 0x06, 0x80, 0x96, 0x11, 0x00, 0x00, 0x00, 0x00,
  0x79, 0x18, 0x00, 0x00, 0x92, 0x00, 0x00, 0x00, 0x1a, 0x03, 0x4c, 0x90,
  0x46, 0x02, 0x13, 0xc4, 0x83, 0x0c, 0x6f, 0x0c, 0x24, 0xc6, 0x45, 0x66,
  0x43, 0x10, 0x4c, 0x10, 0x88, 0x63, 0x82, 0x40, 0x20, 0x1b, 0x84, 0x81,
  0x98, 0x20, 0x10, 0xc9, 0x06, 0x61, 0x30, 0x38, 0xb0, 0xa5, 0x89, 0x4d,
  0x10, 0x08, 0x65, 0xc3, 0x80, 0x24, 0xc4, 0x04, 0x81, 0x58, 0x26, 0x08,
  0x03, 0x40, 0xe7, 0xec, 0x6b, 0x6e, 0x4c, 0xae, 0xac, 0xcc, 0xed, 0xa9,
  0x8e, 0x0e, 0xae, 0x8e, 0x6e, 0x82, 0x40, 0x30, 0x13, 0x04, 0xef, 0x9a,
  0x20, 0x10, 0xcd, 0x06, 0x61, 0x81, 0x36, 0x2c, 0x0b, 0xd3, 0x2c, 0xce,
  0xe0, 0x3c, 0xcf, 0x13, 0x6d, 0x08, 0xa4, 0x0d, 0x04, 0x30, 0x01, 0xc0,
  0x04, 0x41, 0x0c, 0xb2, 0x09, 0x02, 0xe1, 0xb0, 0x19, 0x0b, 0x6b, 0x2b,
  0x93, 0x0b, 0xa3, 0x7a, 0xbb, 0x7a, 0x93, 0x63, 0x23, 0x9b, 0x20, 0x10,
  0xcf, 0x86, 0x01, 0xc3, 0x86, 0x09, 0x02, 0x01, 0x6d, 0x40, 0x92, 0xcb,
  0xc9, 0x88, 0x45, 0x83, 0x38, 0xdd, 0xbd, 0xc9, 0xb1, 0x91, 0x0d, 0x85,
  0xb5, 0x95, 0xc9, 0x85, 0x41, 0xbd, 0xcd, 0xa5, 0xd1, 0xa5, 0xbd, 0xb9,
  0x4d, 0x10, 0x88, 0x68, 0x83, 0x91, 0x70, 0x44, 0xa7, 0x41, 0x3c, 0xe0,
  0xc2, 0xc8, 0xc8, 0xd2, 0xdc, 0xce, 0x26, 0x08, 0x84, 0xb4, 0xc1, 0x48,
  0x3e, 0x02, 0x0c, 0x34, 0x83, 0x8a, 0x5c, 0xd9, 0xdc, 0x1b, 0x5b, 0x1d,
  0x5d, 0xda, 0x9b, 0xdb, 0x04, 0x81, 0x98, 0x36, 0x18, 0x89, 0x18, 0x10,
  0x63, 0xa0, 0x41, 0x1b, 0x0a, 0x6b, 0xf3, 0xc2, 0x80, 0x0c, 0x36, 0x0c,
  0x4b, 0x55, 0x06, 0x13, 0x84, 0x49, 0xd8, 0x00, 0x6c, 0x18, 0x06, 0x34,
  0x40, 0x83, 0x0d, 0x83, 0x83, 0x06, 0x68, 0xb0, 0x61, 0x58, 0xd0, 0x00,
  0x0d, 0x36, 0x0c, 0x69, 0xa0, 0x06, 0x6b, 0xb0, 0x61, 0x18, 0xce, 0x80,
  0x0d, 0x08, 0x4c, 0x10, 0xc6, 0x00, 0xdb, 0x20, 0x2c, 0x6f, 0xb0, 0xa1,
  0x00, 0xdc, 0x00, 0xa0, 0xe0, 0x80, 0xa1, 0x10, 0xf0, 0x83, 0x94, 0x46,
  0x07, 0x04, 0x94, 0x15, 0x84, 0x55, 0x25, 0x15, 0x96, 0x07, 0x15, 0x96,
  0xc7, 0xf6, 0x16, 0x46, 0x06, 0x04, 0x54, 0x25, 0x54, 0x97, 0xc6, 0x46,
  0x97, 0xe4, 0x46, 0x25, 0x97, 0x16, 0xe6, 0x76, 0xc6, 0x56, 0x96, 0xe4,
  0x46, 0x57, 0x26, 0x37, 0x57, 0x36, 0x46, 0x97, 0xf6, 0xe6, 0x16, 0x44,
  0x47, 0x27, 0x97, 0x26, 0x56, 0x47, 0x57, 0x36, 0x07, 0x04, 0x04, 0xa4,
  0x35, 0x41, 0x20, 0xa8, 0x09, 0x02, 0x51, 0x6d, 0x08, 0x96, 0x0d, 0xc8,
  0x1c, 0xd0, 0x41, 0x32, 0x07, 0xda, 0x1c, 0x18, 0x75, 0xb0, 0xa1, 0x38,
  0x03, 0x39, 0x00, 0x00, 0x3b, 0x60, 0x61, 0xc6, 0xf6, 0x16, 0x46, 0xc7,
  0xe7, 0xad, 0xcd, 0x2d, 0x0d, 0xee, 0x8d, 0xae, 0xcc, 0x8d, 0x0e, 0x64,
  0x0c, 0x2d, 0x4c, 0x8e, 0xd1, 0x54, 0x5a, 0x1b, 0x1c, 0x5b, 0x19, 0xc8,
  0xd0, 0xcb, 0xd0, 0xca, 0x0a, 0x08, 0x95, 0x50, 0x50, 0xd0, 0x86, 0x40,
  0x0f, 0x26, 0x08, 0x63, 0x60, 0x6d, 0x18, 0xf2, 0x60, 0x0f, 0xf8, 0x60,
  0xc3, 0x80, 0x07, 0x7d, 0xc0, 0x07, 0x1b, 0x06, 0x3f, 0xf0, 0x03, 0x3e,
  0x20, 0x21, 0xf6, 0xf6, 0xc6, 0xb6, 0x61, 0x00, 0x85, 0x3e, 0xe0, 0x83,
  0x0d, 0x43, 0x28, 0x84, 0x02, 0x1f, 0x6c, 0x10, 0x16, 0x67, 0xc3, 0xd0,
  0x07, 0x7d, 0xc0, 0x07, 0x55, 0xd8, 0xd8, 0xec, 0xda, 0x5c, 0xd2, 0xc8,
  0xca, 0xdc, 0xe8, 0xa6, 0x04, 0x41, 0x15, 0x32, 0x3c, 0x17, 0xbb, 0x32,
  0xb9, 0xb9, 0xb4, 0x37, 0xb7, 0x29, 0x01, 0xd1, 0x84, 0x0c, 0xcf, 0xc5,
  0x2e, 0x8c, 0xcd, 0xae, 0x4c, 0x6e, 0x4a, 0x60, 0xd4, 0x21, 0xc3, 0x73,
  0x99, 0x43, 0x0b, 0x23, 0x2b, 0x93, 0x6b, 0x7a, 0x23, 0x2b, 0x63, 0x9b,
  0x12, 0x24, 0x65, 0xc8, 0xf0, 0x5c, 0xe4, 0xca, 0xe6, 0xde, 0xea, 0xe4,
  0xc6, 0xca, 0xe6, 0xa6, 0x04, 0x53, 0x25, 0x32, 0x3c, 0x17, 0xba, 0x3c,
  0xb8, 0xb2, 0x20, 0x37, 0xb7, 0x37, 0xba, 0x30, 0xba, 0xb4, 0x37, 0xb7,
  0xb9, 0x29, 0x42, 0x19, 0xb0, 0x41, 0x1d, 0x32, 0x3c, 0x97, 0x32, 0x37,
  0x3a, 0xb9, 0x3c, 0xa8, 0xb7, 0x34, 0x37, 0xba, 0xb9, 0x29, 0x02, 0x1c,
  0xd8, 0x01, 0x00, 0x00, 0x79, 0x18, 0x00, 0x00, 0x4c, 0x00, 0x00, 0x00,
  0x33, 0x08, 0x80, 0x1c, 0xc4, 0xe1, 0x1c, 0x66, 0x14, 0x01, 0x3d, 0x88,
  0x43, 0x38, 0x84, 0xc3, 0x8c, 0x42, 0x80, 0x07, 0x79, 0x78, 0x07, 0x73,
  0x98, 0x71, 0x0c, 0xe6, 0x00, 0x0f, 0xed, 0x10, 0x0e, 0xf4, 0x80, 0x0e,
  0x33, 0x0c, 0x42, 0x1e, 0xc2, 0xc1, 0x1d, 0xce, 0xa1, 0x1c, 0x66, 0x30,
  0x05, 0x3d, 0x88, 0x43, 0x38, 0x84, 0x83, 0x1b, 0xcc, 0x03, 0x3d, 0xc8,
  0x43, 0x3d, 0x8c, 0x03, 0x3d, 0xcc, 0x78, 0x8c, 0x74, 0x70, 0x07, 0x7b,
  0x08, 0x07, 0x79, 0x48, 0x87, 0x70, 0x70, 0x07, 0x7a, 0x70, 0x03, 0x76,
  0x78, 0x87, 0x70, 0x20, 0x87, 0x19, 0xcc, 0x11, 0x0e, 0xec, 0x90, 0x0e,
  0xe1, 0x30, 0x0f, 0x6e, 0x30, 0x0f, 0xe3, 0xf0, 0x0e, 0xf0, 0x50, 0x0e,
  0x33, 0x10, 0xc4, 0x1d, 0xde, 0x21, 0x1c, 0xd8, 0x21, 0x1d, 0xc2, 0x61,
  0x1e, 0x66, 0x30, 0x89, 0x3b, 0xbc, 0x83, 0x3b, 0xd0, 0x43, 0x39, 0xb4,
  0x03, 0x3c, 0xbc, 0x83, 0x3c, 0x84, 0x03, 0x3b, 0xcc, 0xf0, 0x14, 0x76,
  0x60, 0x07, 0x7b, 0x68, 0x07, 0x37, 0x68, 0x87, 0x72, 0x68, 0x07, 0x37,
  0x80, 0x87, 0x70, 0x90, 0x87, 0x70, 0x60, 0x07, 0x76, 0x28, 0x07, 0x76,
  0xf8, 0x05, 0x76, 0x78, 0x87, 0x77, 0x80, 0x87, 0x5f, 0x08, 0x87, 0x71,
  0x18, 0x87, 0x72, 0x98, 0x87, 0x79, 0x98, 0x81, 0x2c, 0xee, 0xf0, 0x0e,
  0xee, 0xe0, 0x0e, 0xf5, 0xc0, 0x0e, 0xec, 0x30, 0x03, 0x62, 0xc8, 0xa1,
  0x1c, 0xe4, 0xa1, 0x1c, 0xcc, 0xa1, 0x1c, 0xe4, 0xa1, 0x1c, 0xdc, 0x61,
  0x1c, 0xca, 0x21, 0x1c, 0xc4, 0x81, 0x1d, 0xca, 0x61, 0x06, 0xd6, 0x90,
  0x43, 0x39, 0xc8, 0x43, 0x39, 0x98, 0x43, 0x39, 0xc8, 0x43, 0x39, 0xb8,
  0xc3, 0x38, 0x94, 0x43, 0x38, 0x88, 0x03, 0x3b, 0x94, 0xc3, 0x2f, 0xbc,
  0x83, 0x3c, 0xfc, 0x82, 0x3b, 0xd4, 0x03, 0x3b, 0xb0, 0xc3, 0x8c, 0xcc,
  0x21, 0x07, 0x7c, 0x70, 0x03, 0x74, 0x60, 0x07, 0x37, 0x90, 0x87, 0x72,
  0x98, 0x87, 0x77, 0xa8, 0x07, 0x79, 0x18, 0x87, 0x72, 0x70, 0x83, 0x70,
  0xa0, 0x07, 0x7a, 0x90, 0x87, 0x74, 0x10, 0x87, 0x7a, 0xa0, 0x87, 0x72,
  0x00, 0x00, 0x00, 0x00, 0x71, 0x20, 0x00, 0x00, 0x3d, 0x00, 0x00, 0x00,
  0x25, 0x10, 0x0a, 0x81, 0x1f, 0x32, 0x4d, 0x07, 0x02, 0xb3, 0x41, 0x6c,
  0x55, 0x1a, 0xce, 0x43, 0xc3, 0x79, 0xf6, 0x3b, 0x4c, 0x06, 0x02, 0xab,
  0xc2, 0x7a, 0x9a, 0x4d, 0x4f, 0xba, 0xa9, 0xf2, 0x74, 0xd8, 0x7d, 0x66,
  0x97, 0x93, 0x6e, 0x7a, 0x59, 0x3e, 0x2f, 0x8f, 0xe9, 0xe9, 0xb7, 0x3b,
  0x48, 0xa7, 0xcb, 0xd3, 0xe2, 0x3a, 0xbd, 0x3c, 0x07, 0x02, 0x81, 0xda,
  0x02, 0xa8, 0x83, 0xc0, 0xef, 0xfc, 0x9d, 0x8f, 0xe5, 0xe5, 0xb2, 0xfb,
  0x59, 0xa7, 0xc3, 0xeb, 0x74, 0x20, 0x70, 0x66, 0xfd, 0x91, 0xa4, 0x57,
  0x6a, 0x19, 0x4f, 0xaf, 0xcb, 0xcb, 0x32, 0x22, 0xd0, 0xfa, 0x23, 0xd9,
  0xcb, 0x63, 0xfa, 0x5b, 0x0e, 0x6c, 0x92, 0x60, 0x33, 0x20, 0x10, 0x08,
  0x0c, 0x96, 0x41, 0x1f, 0x90, 0xf1, 0xae, 0x37, 0xdc, 0x35, 0x96, 0x97,
  0xc3, 0xf4, 0x32, 0x32, 0xec, 0x26, 0xb3, 0xcb, 0xc6, 0xb7, 0x9c, 0x99,
  0x16, 0xbb, 0xc6, 0xec, 0xf0, 0x7c, 0xee, 0x92, 0x5e, 0xa9, 0x65, 0x3c,
  0xbd, 0x2e, 0x2f, 0xcb, 0x88, 0x3c, 0x7b, 0x79, 0x4c, 0x7f, 0xcb, 0x79,
  0x66, 0xf6, 0x3b, 0x4c, 0x67, 0x81, 0x68, 0x3e, 0x90, 0xcf, 0x0a, 0xb6,
  0xe1, 0xf2, 0x9d, 0xc7, 0x1f, 0x10, 0xe9, 0x01, 0x26, 0xe1, 0x58, 0x01,
  0x4c, 0x12, 0x9b, 0x81, 0xb8, 0x7c, 0xe4, 0xb6, 0x6d, 0xa0, 0x1a, 0x2e,
  0xdf, 0x79, 0xfc, 0x08, 0xc0, 0x5a, 0x8e, 0x8a, 0x22, 0xa2, 0x99, 0xfc,
  0xe2, 0xb6, 0x8d, 0xc0, 0x1a, 0x2e, 0xdf, 0x79, 0xfc, 0x89, 0xb8, 0x26,
  0x2a, 0x22, 0xd8, 0xc9, 0x89, 0x08, 0xbf, 0xb8, 0x6d, 0x0b, 0x88, 0x96,
  0xa5, 0x62, 0x7c, 0x63, 0x71, 0x02, 0x60, 0xf9, 0x85, 0xc9, 0x89, 0x24,
  0x00, 0x00, 0x00, 0x00, 0x61, 0x20, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00,
  0x13, 0x04, 0x43, 0x2c, 0x10, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x34, 0x96, 0x00, 0x11, 0x25, 0x2a, 0x50, 0xb4, 0x02, 0x05, 0x2c, 0x50,
  0x86, 0x01, 0x33, 0x00, 0x84, 0x8c, 0x00, 0x94, 0x40, 0x79, 0x10, 0x30,
  0x46, 0x00, 0x82, 0x20, 0x88, 0x7f, 0x00, 0x00, 0x74, 0x06, 0xc2, 0x18,
  0x31, 0x28, 0x00, 0x10, 0x04, 0x03, 0xaa, 0x0c, 0x92, 0xdd, 0x0c, 0x8e,
  0x27, 0x06, 0xc3, 0x06, 0x44, 0x20, 0x0c, 0xc0, 0x6e, 0x86, 0xe7, 0xfb,
  0x28, 0x20, 0xc6, 0x70, 0x43, 0x10, 0x06, 0x60, 0x30, 0xcb, 0x10, 0x08,
  0xc1, 0x86, 0x86, 0x48, 0x0c, 0xc4, 0x80, 0x82, 0x67, 0x8c, 0x21, 0x04,
  0xd9, 0x18, 0x82, 0x30, 0x8d, 0x18, 0x18, 0x00, 0x08, 0x82, 0x41, 0xc6,
  0x06, 0x93, 0x33, 0x62, 0x60, 0x00, 0x20, 0x08, 0x06, 0x59, 0x1b, 0x50,
  0xce, 0x88, 0x81, 0x01, 0x80, 0x20, 0x18, 0x6c, 0x6d, 0x30, 0x31, 0x23,
  0x06, 0x0e, 0x00, 0x82, 0x60, 0x70, 0xc1, 0xc1, 0x14, 0x0c, 0x82, 0x54,
  0x10, 0x8e, 0xf3, 0xcc, 0x12, 0x08, 0x18, 0x0e, 0x04, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0xc6, 0x41, 0x00, 0xd3, 0x14, 0xd9, 0xc6, 0xf1,
  0x00, 0xd8, 0xe2, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x31, 0x00, 0x00,
  0x05, 0x00, 0x00, 0x00, 0x5b, 0x86, 0x21, 0xf0, 0x83, 0x2d, 0x45, 0x11,
  0x84, 0x02, 0x21, 0x0a, 0x5b, 0x86, 0x24, 0x18, 0x05, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};