<?php

/**
 * @file Google Civic Voterinfo Template.
 */
?>

<h1>Your <?php print $title; ?> for the <?php print $election_date; ?> Election:</h1>
<div id="google_civic-voterinfo">
<?php if ($locations) : ?>
  <?php foreach ($locations as $location) : ?>
  <div class="google_civic-polling-location vcard">
    <p class="fn org"><?php print $location->address->locationName; ?></p>
    <div class="adr">
      <p class="street-address"><?php print $location->address->line1; ?> <?php print $location->address->line2; ?> <?php print $location->address->line3; ?></p>
      <div>
        <p class="locality"><?php print $location->address->city; ?></p>,
        <p class="region"><?php print $location->address->state; ?></p>
        <p class="postal-code"><?php print $location->address->zip ?></p>
        <p class="country-name"></p>
      </div>
    </div>
  </div>
  <div class="google_civic-polling-hours">
    <p>Polls are open from <span class="google_civic-poll-opening-time"><?php print $location->opening_time; ?></span> - <span class="google_civic-poll-closing-time"><?php print $location->closing_time; ?></span></p>
  </div>
  <?php endforeach; ?>
  <div><?php print $map; ?></div>
  <div>For more information, visit: <?php print $election_info_link; ?></div>
  <?php foreach ($extra_data as $data) : ?>
    <div><?php print $data; ?></div>
  <?php endforeach; ?>
<?php else: ?>
<p>Sorry.  We are unable to find a polling location for your address.</p>
<?php endif; ?>
</div>
