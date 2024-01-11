extends EditorInspectorPlugin

# That plugin used to hide all uniforms inside FastNoiseLiteShaderMaterial
# to prevent direct access to shader parameters.

# Enable only on when editing FastNoiseLiteShaderMaterial
func _can_handle(object):
	if object is FastNoiseLiteShaderMaterial:
		return true
	return false

# Hide shader uniforms
func _parse_property(object, type, name, hint_type, hint_string, usage_flags, wide):
	if name.begins_with("shader_parameter/"): #and not name.contains("debug"):
		return true

# Amogus joke
func _parse_group(object, group):
	if group == "Shader Parameters":
		var hbox = HBoxContainer.new()
		var amogus = TextureRect.new()
		var label = Label.new()
		amogus.set_anchors_preset(Control.PRESET_CENTER)
		label.horizontal_alignment = HORIZONTAL_ALIGNMENT_LEFT
		label.text = "No parameters.\nOnly Amogus =)"
		amogus.texture = preload("shader_parameters_icon.png")
		amogus.expand_mode = TextureRect.SIZE_EXPAND_FILL
		hbox.custom_minimum_size = Vector2(1,110);
		hbox.update_minimum_size()
		hbox.add_child(label)
		hbox.add_spacer(false)
		hbox.add_child(amogus)
		add_custom_control(hbox)
