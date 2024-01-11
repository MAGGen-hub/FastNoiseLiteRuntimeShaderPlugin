@tool
extends EditorPlugin

var plugin

func _enter_tree():
	plugin = preload("res://addons/FastNoiseLiteRuntimeShader/InspectorPlugin.gd").new()
	add_custom_type("FastNoiseLiteShaderMaterial","ShaderMaterial",preload("FastNoiseLiteShaderMaterial.gd"),preload("FastNoiseLiteShaderMaterial.svg"))
	add_inspector_plugin(plugin)


func _exit_tree():
	remove_inspector_plugin(plugin)
	remove_custom_type("FastNoiseLiteShaderMaterial")
