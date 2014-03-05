(function ($) {

/**
 * Responds to visibility toggling.
 */
Drupal.behaviors.gsbFieldAuthors = {
  attach: function (context) {
    $(context).find('.gsb-field-authors-visibility').each(function () {
      new Drupal.GsbFieldAuthorsSelection($(this));
    });
  }
};

/**
 * Creates a new selection object.
 */
Drupal.GsbFieldAuthorsSelection = function ($element) {
  var self = {
    $element: $element,
    entityType: $element.data('gsb-field-authors-entity-type'),
    entityId: $element.data('gsb-field-authors-entity-id')
  };

  self.$element.change(function () {
    var ajax = new Drupal.ajax(false, self.$element, {
      event: 'gsb_field_authors_change',
      url: Drupal.settings.basePath + 'gsb-field-authors/visibility-update/' + self.entityType + '/' + self.entityId + '/' + self.$element.val()
    });
    $(ajax.element).trigger('gsb_field_authors_change');
  });

  $.extend(this, self);
};

/**
 * Process the response from updating the visibility.
 */
Drupal.ajax.prototype.commands.gsb_field_authors_result = function (ajax, response, status) {
};

}(jQuery));
