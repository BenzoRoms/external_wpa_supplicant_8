/*
 * Copyright (C) 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package android.external.wpa_supplicant;

/* import android.os.PersistableBundle; */

interface IWpaSupplicant {

  /**
   * Registers a wireless interface in wpa_supplicant.
   *
   * @param A dictionary with arguments used to add the interface to wpa_supplicant. 
   * The dictionary may contain the following entries:
   *   Ifname(String) Name of the network interface to control, e.g., wlan0
   *   BridgeIfname(String) Name of the bridge interface to control, e.g., br0
   *   Driver(String) Driver name which the interface uses, e.g., nl80211
   *   ConfigFile(String) Configuration file path No
   * @return Binder reference to the object representing created interface
   */
  IBinder CreateInterface();
  //IBinder CreateInterface(PersistableBundle args);
}
