#include"tools.h"

#define GAP 1


EFI_STATUS DrawStep(
    IN UINTN Step
);

EFI_STATUS DrawLogo(
    IN EFI_HANDLE ImageHandle
);

EFI_STATUS SetVideoMode(
    IN EFI_GRAPHICS_OUTPUT_PROTOCOL *Gop
);

typedef struct
{
    EFI_PHYSICAL_ADDRESS       FrameBufferBase;
    UINTN                      FrameBufferSize;
    UINT32                     HorizontalResolution;
    UINT32                     VerticalResolution;
    UINT32                     PixelsPerScanLine;
} VIDEO_CONFIG;