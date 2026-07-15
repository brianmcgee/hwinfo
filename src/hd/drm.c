#include <fcntl.h>
#include <unistd.h>

#include "hd.h"
#include "hd_int.h"

int is_kms_active(hd_data_t *hd_data) {
  int fd = open("/sys/class/drm/card0", O_RDONLY);
  int kms = fd >= 0;
  if (fd >= 0) close(fd);
  ADD2LOG("  KMS detected: %d\n", kms);

  return kms;
}

