/****************************************************************************
 *
 *    Copyright (c) 2024 Vivante Corporation
 *
 *    Permission is hereby granted, free of charge, to any person obtaining a
 *    copy of this software and associated documentation files (the "Software"),
 *    to deal in the Software without restriction, including without limitation
 *    the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *    and/or sell copies of the Software, and to permit persons to whom the
 *    Software is furnished to do so, subject to the following conditions:
 *
 *    The above copyright notice and this permission notice shall be included in
 *    all copies or substantial portions of the Software.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *    DEALINGS IN THE SOFTWARE.
 *
 *****************************************************************************/

#ifndef VSI_ANDROID_SL_DEVICE_MANAGER_H
#define VSI_ANDROID_SL_DEVICE_MANAGER_H

#include <memory>

#include "Device.h"
#include "tim/vx/platform/platform.h"

namespace vsi::android::sl {

class DeviceManager {
   public:
    static DeviceManager* get() {
        static DeviceManager manager;
        return &manager;
    }

    [[nodiscard]] size_t getNumDevices() { return devices_.size(); }
    [[nodiscard]] const std::vector<std::shared_ptr<Device>>& getDevices() { return devices_; }

   private:
    DeviceManager();  // NOLINT(modernize-use-equals-delete)

    std::vector<std::shared_ptr<Device>> devices_;
};

}  // namespace vsi::android::sl

#endif