# This file is executed on every boot (including wake-boot from deepsleep)

WIFI_SSID = "<wifi ssid>"
WIFI_PSK = "<wifi passphrase>"

def ap_disable():
    import network
    ap = network.WLAN(network.AP_IF)
    ap.active(False)

def wifi_connect():
    import network
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    if not wlan.isconnected():
        print('connecting to network...')
        wlan.connect(WIFI_SSID, WIFI_PSK)
        while not wlan.isconnected():
            pass
    print('network config:', wlan.ifconfig())

def wifi_disable():
    import network
    wlan = network.WLAN(network.STA_IF)
    wlan.active(False)
    print("WiFi disabled")

ap_disable()
wifi_connect()
# wifi_disable()
