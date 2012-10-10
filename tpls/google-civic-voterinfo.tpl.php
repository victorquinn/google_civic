<?php

/**
 * @file Google Civic Voterinfo Template.
 */
?>

<div id="google-civic-voterinfo-heading">
  <?php print $headline; ?>
</div>
<div id="google-civic-voterinfo">
<?php if ($locations) : ?>
  <?php foreach ($locations as $location) : ?>
  <div class="google-civic-voterinfo-polling-location vcard">
    <p class="fn org"><?php print $location->address->locationName; ?></p>
    <div class="adr">
      <p class="street-address">
        <?php print $location->address->line1; ?>
        <?php print $location->address->line2; ?>
        <?php print $location->address->line3; ?>
      </p>
      <div>
        <p class="locality"><?php print $location->address->city; ?></p>,
        <p class="region"><?php print $location->address->state; ?></p>
        <p class="postal-code"><?php print $location->address->zip ?></p>
        <p class="country-name"></p>
      </div>
    </div>
  </div>
  <div class="google-civic-voterinfo-polling-hours">
  <?php if ($location->opening_time) : ?>
    <p>Polls are open from 
      <span class="google-civic-voterinfo-poll-opening-time">
        <?php print $location->opening_time; ?>
      </span> - 
      <span class="google-civic-voterinfo-poll-closing-time">
        <?php print $location->closing_time; ?>
      </span>
    </p>
  <?php else : ?>
    <p>Sorry.  We're unable to find polling hours for this location.</p>
  <?php endif; ?>
  </div>
  <?php endforeach; ?>
<?php else: ?>
  <p>Sorry.  We are unable to find a polling location for your address.</p>
<?php endif; ?>

<?php if ($early_locations) : ?>
  <?php foreach ($locations as $location) : ?>
  <div class="google-civic-voterinfo-early-polling-location vcard">
    <p class="fn org"><?php print $location->address->locationName; ?></p>
    <div class="adr">
      <p class="street-address">
        <?php print $location->address->line1; ?>
        <?php print $location->address->line2; ?>
        <?php print $location->address->line3; ?>
      </p>
      <div>
        <p class="locality"><?php print $location->address->city; ?></p>,
        <p class="region"><?php print $location->address->state; ?></p>
        <p class="postal-code"><?php print $location->address->zip ?></p>
        <p class="country-name"></p>
      </div>
    </div>
  </div>
  <div class="google-civic-voterinfo-early-polling-hours">
  <?php if ($location->opening_time) : ?>
    <p>Polls are open from 
      <span class="google-civic-voterinfo-early-poll-opening-time">
        <?php print $location->opening_time; ?>
      </span> - 
      <span class="google-civic-voterinfo-early-poll-closing-time">
        <?php print $location->closing_time; ?>
      </span>
    </p>
  <?php else : ?>
    <p>Sorry.  We're unable to find polling hours for this location.</p>
  <?php endif; ?>
  </div>
  <?php endforeach; ?>
<?php endif; ?>

<?php if ($map) : ?>
  <div id="google-civic-voterinfo-gmap"><?php print $map; ?></div>
<?php endif; ?>

<?php if ($election_info_link) : ?>
  <div id="google-civic-voterinfo-election-info">For more information, visit:
    <?php print $election_info_link; ?>
  </div>
<?php endif; ?>

</div>
<div id="google-civic-address-form-div">
  <p>Find voter information for another address:</p>
  <?php print $address_form; ?>
</div>
