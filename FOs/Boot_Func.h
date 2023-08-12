#include<Library/UefiBootServicesTableLib.h>
#include<Uefi.h>
#include<Library/UefiLib.h>
#include<Library/UefiBootServicesTableLib.h>
#include <Protocol/GraphicsOutput.h>
#include <Library/BaseMemoryLib.h>
EFI_STATUS Draw_FOs_GRAPHICS(
    IN EFI_HANDLE ImageHandle
);

EFI_STATUS GetGopHandle(
    IN EFI_HANDLE ImageHandle,
    OUT EFI_GRAPHICS_OUTPUT_PROTOCOL **Gop
);