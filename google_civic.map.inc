<?php

/**
 * Gets a GMap-style marker for a Google Civic location.
 *
 * @param string $address
 *   An address string.
 *
 * @return Array
 *   A GMap-style map marker.
 */
function google_civic_address_marker($address) {
  $geocode_data = gmap_geocode($address);
  $marker = google_civic_map_marker($geocode_data['latitude'],
                                    $geocode_data['longitude'], '');
  return $marker;
}

/**
 * Maps Google Civic polling locations around the current address.
 *
 * @param string $address
 *   An address string.
 * @param Array $locations
 *   A list of location responses (massaged) from Google Civic.
 *
 * @return string
 *   A map--rendered as HTML.
 */
function google_civic_map($address, $locations) {
  $home_marker = google_civic_address_marker($address);

  $map = array();
  $map['id'] = gmap_get_auto_mapid();
  $map['zoom'] = 'auto';
  $map['autoshow'] = FALSE;
  $map['markers'] = array();

  google_civic_map_add_marker($map, $home_marker);
  foreach($locations as $location) {
    google_civic_map_add_marker($map, $location->marker);
  }

  return theme('gmap', array('#settings' => $map,));
}

/**
 * Adds a marker to to a map.
 *
 * @param Array $map
 *   A GMap-style map array.
 * @param Array $marker
 *   A GMap-style map marker array.
 */
function google_civic_map_add_marker(&$map, $marker) {
  // Center the map if it does not have a center.
  if (!isset($map['latitude']) || !$map['latitude']) {
    $map['latitude'] = $marker['latitude'];
    $map['longitude'] = $marker['longitude'];
  }

  $map['markers'][] = $marker;
}

/**
 * Creates a GMap-style map marker array.
 *
 * @param float $latitude
 *   A Google Maps latitude.
 * @param float $longitude
 *   A Google Maps longitude.
 * @param string $markername
 *   A marker name (caption / title of the marker).
 * @param int $offset
 *   A Google Maps offset.
 *
 * @return Array
 *   A GMaps-style map marker array.
 */
function google_civic_map_marker($latitude, $longitude,
                                 $markername, $offset = 0) {

  $marker = array(
    'latitude' => $latitude,
    'longitude' => $longitude,
    'markername' => $markername,
    /**
     * coderev-google_civic
     * Should offset always be 0?  Even when consuming code passes in a
     * different parameter?
     */
    'offset' => 0,
  );
  return $marker;
}

