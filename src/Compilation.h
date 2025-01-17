/****************************************************************************
 *
 *    Copyright (c) 2022 Vivante Corporation
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
#ifndef VSI_ANDROID_SL_COMPILATION_H
#define VSI_ANDROID_SL_COMPILATION_H
#include <memory>
#include <unordered_map>

#include "Model.h"
#include "VsiDevice.h"
#include "slang/type_system.h"
#include "tim/vx/ops.h"

namespace vsi {
namespace android {
namespace sl {

class Compilation {
   public:
    Compilation(Model* model) : model_(model) {}
    Compilation(Model* model, const std::vector<const VsiDevice*> devices)
        : model_(model), devices_(devices) {}
    int Finish() {
        finished_ = true;
        return ANEURALNETWORKS_NO_ERROR;
    }
    Model* GetModel() { return model_; }
    Model* GetModel() const { return model_; }
    const std::vector<const VsiDevice*>& Devices() { return devices_; }
    int SetPreference(PreferenceCode preference) {
        preference_ = preference;
        return ANEURALNETWORKS_NO_ERROR;
    }
    int SetPriority(PriorityCode priority) {
        priority_ = priority;
        return ANEURALNETWORKS_NO_ERROR;
    }
    int SetTimeout(DurationCode duration) {
        duration_ = duration;
        return ANEURALNETWORKS_NO_ERROR;
    }

   private:
    Model* model_;
    PreferenceCode preference_;
    PriorityCode priority_;
    DurationCode duration_;
    const std::vector<const VsiDevice*> devices_;
    bool finished_{false};
};

}  // namespace sl
}  // namespace android
}  // namespace vsi

#endif