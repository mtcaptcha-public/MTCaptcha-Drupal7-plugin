<?php

/**
 * @file
 * Provides the MTCaptcha administration settings.
 */

function mtcaptcha_admin_settings() {
  $form['mtcaptcha_general_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
  );

  $form['mtcaptcha_general_settings']['mtcaptcha_site_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Site key'),
    '#default_value' => variable_get('mtcaptcha_site_key', ''),
    '#maxlength' => 40,
    '#description' => t('The site key given to you when you <a href="@url">register for mtcaptcha</a>.', array('@url' => 'https://admin.mtcaptcha.com/signup/profile?plantype=A')),
    '#required' => TRUE,
  );
  $form['mtcaptcha_general_settings']['mtcaptcha_private_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Private key'),
    '#default_value' => variable_get('mtcaptcha_private_key', ''),
    '#maxlength' => 128,
    '#description' => t('The private key given to you when you <a href="@url">register for mtcaptcha</a>.', array('@url' => 'https://admin.mtcaptcha.com/signup/profile?plantype=A')),
    '#required' => TRUE,
  );

  $form['mtcaptcha_widget_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Widget settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['mtcaptcha_widget_settings']['mtcaptcha_theme'] = array(
    '#type' => 'select',
    '#title' => t('Theme'),
    '#description' => t('Defines which theme to use for mtcaptcha.'),
    '#options' => [
      'standard' => t('standard'),
      'overcast' => t('overcast'),
      'neowhite' => t('neowhite'),
      'goldbezel' => t('goldbezel'),
      'blackmoon' => t('blackmoon'),
      'darkruby' => t('darkruby'),
      'touchoforange' => t('touchoforange'),
      'caribbean' => t('caribbean'),
      'woodyallen' => t('woodyallen'),
      'chrome' => t('chrome'),
      'highcontrast' => t('highcontrast'),
    ],
    '#default_value' => variable_get('mtcaptcha_theme', 'standard')
  );
  $form['mtcaptcha_widget_settings']['mtcaptcha_language'] = array(
    '#type' => 'select',
    '#title' => t('Language'),
    '#description' => t('Language the labels need to be displayed.'),
    '#options' => [
      'en' => t('English(en)'),
      'ar' => t('Arabic(ar)'),
      "af" => t("Afrikaans(af)"),
      "am" => t("Amharic(am)"),
      "hy" => t("Armenian(hy)"),
      "az" => t("Azerbaijani(az)"),
      "eu" => t("Basque(eu)"),
      "bn" => t("Bengali(bn)"),
      "bg" => t("Bulgarian(bg)"),
      "ca" => t("Catalan(ca)"),
      "zh-hk" => t("Chinese (Hong Kong)(zh-HK)"),
      "zh" => t("Chinese(zh)"),
      "hr" => t("Croatian(hr)"),
      "cs" => t("Czech(cs)"),
      "da" => t("Danish(da)"),
      "nl" => t("Dutch(nl)"),
      "en" => t("English"),
      "et" => t("Estonian(et)"),
      "fil" => t("Filipino(fil)"),
      "fi" => t("Finnish(fi)"),
      "fr" => t("French(fr)"),
      "gl" => t("Galician(gl)"),
      "ka" => t("Georgian(ka)"),
      "de" => t("German(de)"),
      "el" => t("Greek(el)"),
      "gu" => t("Gujarati(gu)"),
      "iw" => t("Hebrew(iw)"),
      "hi" => t("Hindi(hi)"),
      "hu" => t("Hungarain(hu)"),
      "is" => t("Icelandic(is)"),
      "id" => t("Indonesian(id)"),
      "it" => t("Italian(it)"),
      "ja" => t("Japanese(ja)"),
      "kn" => t("Kannada(kn)"),
      "ko" => t("Korean(ko)"),
      "ko" => t("Korean(ko)"),
      "lv" => t("Latvian(lv)"),
      "lt" => t("Lithuanian(lt)"),
      "ms" => t("Malay(ms)"),
      "ml" => t("Malayalam(ml)"),
      "mr" => t("Marathi(mr)"),
      "mn" => t("Mongolian(mn)"),
      "no" => t("Norwegian(no)"),
      "fa" => t("Persian(fa)"),
      "pl" => t("Polish(pl)"),
      "pt" => t("Portuguese(pt)"),
      "ro" => t("Romanian(ro)"),
      "ru" => t("Russian(ru)"),
      "si" => t("Sinhalese(si)"),
      "sr" => t("Serbian(sr)"),
      "sk" => t("Slovak(sk)"),
      "sl" => t("Slovenian(sl)"),
      "es" => t("Spanish(es)"),
      "sw" => t("Swahili(sw)"),
      "sv" => t("Swedish(sv)"),
      "ta" => t("Tamil(ta)"),
      "te" => t("Telugu(te)"),
      "th" => t("Thai(th)"),
      "tr" => t("Turkish(tr)"),
      "uk" => t("Ukrainian(uk)"),
      "ur" => t("Urdu(ur)"),
      "vi" => t("Vietnamese(vi)"),
      "zu" => t("Zulu(zu)")
    ],
    '#default_value' => variable_get('mtcaptcha_language', 'en'),
  );
  $form['mtcaptcha_widget_settings']['mtcaptcha_widgetsize'] = [
    '#default_value' => variable_get('mtcaptcha_widgetsize'),
    '#description' => t('Defines which widgetsize to use for mtcaptcha.'),
    '#options' => [
      'standard' => t('Standard'),
      'mini' => t('Modern Mini'),
    ],
    '#title' => t('Captcha Widget size'),
    '#type' => 'select',    
  ];

  $form['mtcaptcha_widget_settings']['mtcaptcha_enablecaptcha'] = array(
    "#type" => "select",
    "#title" => t("Enable MTCaptcha For"),
    "#options" => array(
      "all" => t("All Users"),
      "login" => t("Logged In Users"),
      "logout" => t("Logged Out Users"),      
    ),    
    "#default_value" => variable_get('mtcaptcha_enablecaptcha', "all"),
    "#description" => t('<br> The MTCaptcha will be embedded in Login Form and 
    Reset Password Form even though the Enable MTCaptcha is selected for logged <br> in users. If needed we can disable 
    MTCaptcha for these forms by choosing below options')
  );

  $form_ids = array(
    'user_login' => t('Login Form'),
    'user_register_form' => t('Registration Form'), 
    'user_pass' => t('Reset Password Form'),
    'user_profile_form' => t('Change Password Form'),
    'comment_node_article_form' => t('Comment Form'),
    'contact_site_form' => t('Contact Form')
  );

  $form['mtcaptcha_widget_settings']['mtcaptcha_enable'] = array(
    '#title' => t('MTCaptcha is applied for'),
    '#type' => 'checkboxes',
    '#default_value' => variable_get('mtcaptcha_enable', array()),
    '#description' => t('Please enable MTCaptcha for above forms'),
    '#options' => $form_ids,
  );

  $form['mtcaptcha_widget_settings']['mtcaptcha_other_enable'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Forms to Enable'),
    '#default_value' => variable_get('mtcaptcha_other_enable', ''),
    '#description' => t('Please give other form ids mtcaptcha should be enabled'),
    '#maxlength' => 400,
  );

  return system_settings_form($form);
}
