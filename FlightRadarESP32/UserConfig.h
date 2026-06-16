#pragma once
#include "Types.h"

//====================================================
// STANDORTMODUS
//====================================================
#define LOCATION_MODE_FIXED 1
#define LOCATION_MODE_GPS   2

#define LOCATION_MODE LOCATION_MODE_FIXED

//====================================================
// STANDARD- / FESTER STANDORT
//====================================================
static const double DEFAULT_USER_LAT = 51.1657;
static const double DEFAULT_USER_LON = 10.4515;

// Deutschland: UTC +01:00, Sommerzeit +01:00 zusätzlich
static const long DEFAULT_GMT_OFFSET_SEC = 3600;
static const int DEFAULT_DAYLIGHT_OFFSET_SEC = 3600;
static const float DEFAULT_LOCAL_TIMEZONE_HOURS = 1.0f;

//====================================================
// GPS-KONFIGURATION
//====================================================
#define ENABLE_GPS 0
#define GPS_RX_PIN 16
#define GPS_TX_PIN 17
#define GPS_BAUD   9600

// Wenn aktiviert, darf das GPS den Standort und die UTC-Zeit aktualisieren.
// DEFAULT_GMT_OFFSET_SEC / DEFAULT_LOCAL_TIMEZONE_HOURS solltest du trotzdem passend setzen.
#define GPS_REQUIRE_FIX_BEFORE_FETCH 0

//====================================================
// WLAN-PORTAL
//====================================================
#define WIFI_PORTAL_SSID "FlightRadarESP32"
#define WIFI_PORTAL_TIMEOUT_SEC 180
#define WIFI_CONNECT_TIMEOUT_SEC 30

//====================================================
// DEBUG
//====================================================
#define DEBUG_SERIAL 0

//====================================================
// STERNBILDER / HIMMELSANZEIGE
//====================================================
#define CONSTELLATION_AUTO_NIGHT 0
#define CONSTELLATION_ALWAYS     1
#define CONSTELLATION_OFF        2

// Sternbilder im Hintergrund:
// - CONSTELLATION_AUTO_NIGHT = nur nachts anzeigen
// - CONSTELLATION_ALWAYS     = immer anzeigen
// - CONSTELLATION_OFF        = komplett ausschalten
#define CONSTELLATION_MODE CONSTELLATION_OFF

// Zusätzliche Anzeigeelemente auf dem Radar:
// 1 = anzeigen, 0 = ausblenden
#define SHOW_SUN_MOON_TRACKER 0
#define SHOW_TIME_DOTS        0
#define SHOW_RADAR_SWEEP      1

//====================================================
// NETZWERK- / SPEICHERKONFIGURATION
//====================================================
// Bei klassischen ESP32-Boards kann das helfen, wenn HTTPS wegen Speichermangel Probleme macht.
// In diesem Low-Memory-Build bleibt es aus, damit das Display nicht bei jedem Update auf FETCHING springt.
#define FREE_DISPLAY_SPRITE_DURING_HTTPS 0

//====================================================
// FLUGZEUG- / RADAR-KONFIGURATION
//====================================================
#ifndef MAX_AIRCRAFT
#define MAX_AIRCRAFT 25
#endif
#ifndef MAX_TRAIL_POINTS
#define MAX_TRAIL_POINTS 16
#endif

static const uint32_t DISPLAY_INTERVAL_MS = 33;
static const uint32_t TRAIL_INTERVAL_MS = 1000;    // 16 Punkte x 1000 ms = ca. 16 Sekunden Verlauf
static const uint32_t INFO_TEMPLATE_INTERVAL_MS = 5000;
static const uint32_t SELECT_SWITCH_INTERVAL_MS = 10000;
static const uint32_t MAP_ZOOM_INTERVAL_MS = 40000;

static const uint32_t ADSB_UPDATE_INTERVAL_MS = 10000;
static const uint32_t OPENSKY_UPDATE_INTERVAL_MS = 30000;
static const uint32_t ADSB_RETRY_INTERVAL_MS = 60000;

static const int ADSB_RADIUS_NM = 135;
static const double OPENSKY_BOX_DEG = 2.35;

static const size_t ADSB_JSON_DOC_BYTES = 32768;
static const size_t OPENSKY_JSON_DOC_BYTES = 49152;

static const int ZOOM_LEVEL_COUNT = 10;
static const float ZOOM_LEVELS_KM[ZOOM_LEVEL_COUNT] = {
  25.0f, 50.0f, 100.0f, 150.0f, 200.0f,
  250.0f, 200.0f, 150.0f, 100.0f, 50.0f
};

//====================================================
// API-KONFIGURATION
//====================================================
static const char ADSB_BASE_URL[] = "https://api.adsb.lol/v2/point/";
static const char OPENSKY_BASE_URL[] = "https://opensky-network.org/api/states/all";

//====================================================
// BENUTZERDEFINIERTE FLUGHAFEN-MARKER
//====================================================
// Diese Marker kannst du auf deine Region anpassen.
// Für gute Lesbarkeit sind etwa 3 bis 8 Marker sinnvoll.
static const AirportMarker USER_AIRPORTS[] = {
  { "FRA", 50.037900f, 8.562200f,  true,   0,   0 },
  { "MUC", 48.353800f, 11.786100f, false,  0,   0 },
  { "BER", 52.366700f, 13.503300f, false,  0,   0 },
  { "HAM", 53.630400f, 9.988200f,  false,  0,   0 },
  { "DUS", 51.289500f, 6.766800f,  false,  0,   0 }
};

static const int USER_AIRPORT_COUNT = sizeof(USER_AIRPORTS) / sizeof(USER_AIRPORTS[0]);
