#include <Library/BaseMemoryLib.h>
#include <Protocol/GraphicsOutput.h>
#include <Library/BaseMemoryLib.h>
#include  <Library/MemoryAllocationLib.h>
#include <Uefi.h>
#include <Guid/FileInfo.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Protocol/SimpleFileSystem.h>

EFI_STATUS GetGopHandle(
    IN EFI_HANDLE ImageHandle,
    EFI_GRAPHICS_OUTPUT_PROTOCOL **Gop
);