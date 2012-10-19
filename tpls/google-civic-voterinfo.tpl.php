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
    <div id="google-civic-voterinfo-polling-locations">
      <?php print $locations; ?>
    </div>
  <?php else: ?>
    <p><?php print 
      t('Sorry.  We are unable to find a polling location for your address.');
    ?></p>
  <?php endif; ?>

  <?php if ($map) : ?>
    <div id="google-civic-voterinfo-gmap"><?php print $map; ?></div>
  <?php endif; ?>

  <?php if ($early_locations) : ?>
    <div id="google-civic-voterinfo-early-locations" class="clearfix">
      <div id="google-civic-voterinfo-early-locations-title">
        <?php print t('Early Voting Sites'); ?>
      </div>
      <?php print $early_locations; ?>
    </div>
  <?php endif; ?>

  <?php if ($election_info_link) : ?>
    <div id="google-civic-voterinfo-election-info">
      <?php print 
        t('For more information, visit: !link', 
            array('!link' => $election_info_link)); 
      ?>
    </div>
  <?php endif; ?>

</div>
<div id="google-civic-address-form-div">
  <?php print $address_form; ?>
</div>

