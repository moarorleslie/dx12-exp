#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.1
//
//
// Buffer Definitions: 
//
// cbuffer PSConstants
// {
//
//   float3 SunDirection;               // Offset:    0 Size:    12 [unused]
//   float3 SunColor;                   // Offset:   16 Size:    12 [unused]
//   float3 AmbientColor;               // Offset:   32 Size:    12 [unused]
//   float4 ShadowTexelSize;            // Offset:   48 Size:    16 [unused]
//   float4 InvTileDim;                 // Offset:   64 Size:    16
//   uint4 TileCount;                   // Offset:   80 Size:    16
//   uint4 FirstLightIndex;             // Offset:   96 Size:    16 [unused]
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim      HLSL Bind  Count
// ------------------------------ ---------- ------- ----------- -------------- ------
// lightGrid                         texture    byte         r/o            t68      1 
// PSConstants                       cbuffer      NA          NA            cb0      1 
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Position              0   xyzw        0      POS   float   xy  
// worldPos                 0   xyz         1     NONE   float       
// texcoord                 0   xy          2     NONE   float       
// texcoord                 1   xyz         3     NONE   float       
// texcoord                 2   xyz         4     NONE   float       
// normal                   0   xyz         5     NONE   float       
// tangent                  0   xyz         6     NONE   float       
// bitangent                0   xyz         7     NONE   float       
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyz         0   TARGET   float   xyz 
//
// Pixel Shader runs at sample frequency
//
ps_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[6], immediateIndexed
dcl_resource_raw t68
dcl_input_ps_siv linear noperspective sample v0.xy, position
dcl_output o0.xyz
dcl_temps 1
mul r0.xy, v0.xyxx, cb0[4].xyxx
ftou r0.xy, r0.xyxx
imad r0.x, r0.y, cb0[5].x, r0.x
imul null, r0.x, r0.x, l(516)
ld_raw_indexable(raw_buffer)(mixed,mixed,mixed,mixed) r0.x, r0.x, t68.xxxx
and r0.y, r0.x, l(255)
ubfe r0.xz, l(8, 0, 8, 0), l(8, 0, 16, 0), r0.xxxx
iadd r0.x, r0.x, r0.y
iadd r0.x, r0.z, r0.x
utof r0.x, r0.x
mad o0.xyz, r0.xxxx, l(0.031250, -0.031250, 0.000000, 0.000000), l(0.000000, 1.000000, 0.000000, 0.000000)
ret 
// Approximately 12 instruction slots used
#endif

const BYTE g_pWaveTileCountPS[] =
{
     68,  88,  66,  67, 139, 121, 
    103, 152, 111,  69, 122,  85, 
    104,  82,  46, 143, 232,  49, 
    107,  25,   1,   0,   0,   0, 
    248,   7,   0,   0,   6,   0, 
      0,   0,  56,   0,   0,   0, 
      8,   3,   0,   0,  16,   4, 
      0,   0,  68,   4,   0,   0, 
     28,   6,   0,   0, 184,   6, 
      0,   0,  82,  68,  69,  70, 
    200,   2,   0,   0,   1,   0, 
      0,   0, 148,   0,   0,   0, 
      2,   0,   0,   0,  60,   0, 
      0,   0,   0,   5, 255, 255, 
      0,   1,   0,   0, 160,   2, 
      0,   0,  82,  68,  49,  49, 
     60,   0,   0,   0,  24,   0, 
      0,   0,  32,   0,   0,   0, 
     40,   0,   0,   0,  36,   0, 
      0,   0,  12,   0,   0,   0, 
      0,   0,   0,   0, 124,   0, 
      0,   0,   7,   0,   0,   0, 
      6,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     68,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    134,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 108, 105, 103, 104, 
    116,  71, 114, 105, 100,   0, 
     80,  83,  67, 111, 110, 115, 
    116,  97, 110, 116, 115,   0, 
    171, 171, 134,   0,   0,   0, 
      7,   0,   0,   0, 172,   0, 
      0,   0, 112,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 196,   1,   0,   0, 
      0,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    216,   1,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    252,   1,   0,   0,  16,   0, 
      0,   0,  12,   0,   0,   0, 
      0,   0,   0,   0, 216,   1, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,   5,   2, 
      0,   0,  32,   0,   0,   0, 
     12,   0,   0,   0,   0,   0, 
      0,   0, 216,   1,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  18,   2,   0,   0, 
     48,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
     44,   2,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     80,   2,   0,   0,  64,   0, 
      0,   0,  16,   0,   0,   0, 
      2,   0,   0,   0,  44,   2, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  91,   2, 
      0,   0,  80,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 108,   2,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 144,   2,   0,   0, 
     96,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
    108,   2,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     83, 117, 110,  68, 105, 114, 
    101,  99, 116, 105, 111, 110, 
      0, 102, 108, 111,  97, 116, 
     51,   0,   1,   0,   3,   0, 
      1,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 209,   1, 
      0,   0,  83, 117, 110,  67, 
    111, 108, 111, 114,   0,  65, 
    109,  98, 105, 101, 110, 116, 
     67, 111, 108, 111, 114,   0, 
     83, 104,  97, 100, 111, 119, 
     84, 101, 120, 101, 108,  83, 
    105, 122, 101,   0, 102, 108, 
    111,  97, 116,  52,   0, 171, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  34,   2, 
      0,   0,  73, 110, 118,  84, 
    105, 108, 101,  68, 105, 109, 
      0,  84, 105, 108, 101,  67, 
    111, 117, 110, 116,   0, 117, 
    105, 110, 116,  52,   0, 171, 
      1,   0,  19,   0,   1,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 101,   2,   0,   0, 
     70, 105, 114, 115, 116,  76, 
    105, 103, 104, 116,  73, 110, 
    100, 101, 120,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  49,  48,  46, 
     49,   0,  73,  83,  71,  78, 
      0,   1,   0,   0,   8,   0, 
      0,   0,   8,   0,   0,   0, 
    200,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   3,   0,   0, 
    212,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   7,   0,   0,   0, 
    221,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   3,   0,   0,   0, 
    221,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,   7,   0,   0,   0, 
    221,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   4,   0, 
      0,   0,   7,   0,   0,   0, 
    230,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   5,   0, 
      0,   0,   7,   0,   0,   0, 
    237,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   6,   0, 
      0,   0,   7,   0,   0,   0, 
    245,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   7,   0, 
      0,   0,   7,   0,   0,   0, 
     83,  86,  95,  80, 111, 115, 
    105, 116, 105, 111, 110,   0, 
    119, 111, 114, 108, 100,  80, 
    111, 115,   0, 116, 101, 120, 
     99, 111, 111, 114, 100,   0, 
    110, 111, 114, 109,  97, 108, 
      0, 116,  97, 110, 103, 101, 
    110, 116,   0,  98, 105, 116, 
     97, 110, 103, 101, 110, 116, 
      0, 171,  79,  83,  71,  78, 
     44,   0,   0,   0,   1,   0, 
      0,   0,   8,   0,   0,   0, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   7,   8,   0,   0, 
     83,  86,  95,  84,  97, 114, 
    103, 101, 116,   0, 171, 171, 
     83,  72,  69,  88, 208,   1, 
      0,   0,  80,   0,   0,   0, 
    116,   0,   0,   0, 106,   8, 
      0,   1,  89,   0,   0,   4, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   6,   0,   0,   0, 
    161,   0,   0,   3,   0, 112, 
     16,   0,  68,   0,   0,   0, 
    100,  56,   0,   4,  50,  16, 
     16,   0,   0,   0,   0,   0, 
      1,   0,   0,   0, 101,   0, 
      0,   3, 114,  32,  16,   0, 
      0,   0,   0,   0, 104,   0, 
      0,   2,   1,   0,   0,   0, 
     56,   0,   0,   8,  50,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  16,  16,   0,   0,   0, 
      0,   0,  70, 128,  32,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,  28,   0,   0,   5, 
     50,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,  35,   0, 
      0,  10,  18,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     10, 128,  32,   0,   0,   0, 
      0,   0,   5,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  38,   0,   0,   8, 
      0, 208,   0,   0,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      4,   2,   0,   0, 165,   0, 
      0, 137, 194,   2,   0, 128, 
    131, 153,  25,   0,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   6, 112,  16,   0, 
     68,   0,   0,   0,   1,   0, 
      0,   7,  34,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0, 255,   0, 
      0,   0, 138,   0,   0,  15, 
     82,   0,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      8,   0,   0,   0,   0,   0, 
      0,   0,   8,   0,   0,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   8,   0,   0,   0, 
      0,   0,   0,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,  16,   0,   0,   0, 
      0,   0,  30,   0,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     30,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  86,   0, 
      0,   5,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,  15, 114,  32, 
     16,   0,   0,   0,   0,   0, 
      6,   0,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,  61,   0,   0, 
      0, 189,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 128,  63,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 148,   0,   0,   0, 
     12,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   2,   0, 
      0,   0,   4,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  82,  84, 
     83,  48,  56,   1,   0,   0, 
      2,   0,   0,   0,   6,   0, 
      0,   0,  24,   0,   0,   0, 
      2,   0,   0,   0, 208,   0, 
      0,   0,   1,   0,   0,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,  96,   0,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0, 108,   0,   0,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0, 120,   0,   0,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0, 152,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 184,   0,   0,   0, 
      1,   0,   0,   0,   5,   0, 
      0,   0, 196,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0, 128,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   1,   0,   0,   0, 
    160,   0,   0,   0,   0,   0, 
      0,   0,   6,   0,   0,   0, 
     64,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  85,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    127, 127,   0,   0,   0,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,  20,   0,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  16,   0, 
      0,   0,   7,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0, 255, 255, 127, 127, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   5,   0,   0,   0
};